#include <type_traits>
#include <QMenu>
#include <QMessageBox>
#include <QDebug>
#include "tray.h"
#include "clipboard.h"

void renderMenu(QMenu *menu, QList<QAction*> data, QList<QAction*> controls)
{
    menu->clear();
    menu->addActions(data);
    menu->addSeparator();
    menu->addActions(controls);
}

Tray::Tray(const QString &filename, Clipboard &clipboard):
    clipboard(clipboard),
    menu(new QMenu()),
    loginWin(new LoginWindow()),
    controlActions(QList<QAction*>()),
    dataActions(QList<QAction*>())
{
    menu->setStyleSheet("QMenu {background: #373f49; color: #fff;}"
                        "QMenu::item:selected{background: #47505c;}"
                        "QMenu::item:disabled{background: #373f49; color: gray}");
//                        "QMenu::icon {background-color: black;}");

    auto login = new QAction("Log In");
    connect(login, &QAction::triggered, [this](){
        loginWin->show();
    });

    auto logout = new QAction("Log Out");
    logout->setEnabled(false);

    auto aboutAction = new QAction("About");

    auto exitAction = new QAction("Exit");
    connect(exitAction, &QAction::triggered, this, [](){
        exit(0);
    });

    controlActions.push_back(login);
    controlActions.push_back(logout);
    controlActions.push_back(aboutAction);
    controlActions.push_back(exitAction);

    auto loadingAction = new QAction("Syncing...");
    loadingAction->setEnabled(false);
    dataActions.push_back(loadingAction);

    renderMenu(menu, dataActions, controlActions);

    auto trayIcon = new QSystemTrayIcon(QIcon(filename), this);
    trayIcon->show();
    trayIcon->setContextMenu(menu);
//    trayIcon->setVisible(true);
//    trayIcon->showMessage("test1", "test2", QSystemTrayIcon::Information, 1000);

//    connect(trayIcon, &QSystemTrayIcon::activated, [this, trayIcon](auto r){
//        if (r == QSystemTrayIcon::ActivationReason::Trigger) {
//            this->updateMenuList(QList<QVariant>{"test"}, [trayIcon](auto r){
//                qDebug() << r;
//            });
//        }
//    });
    connect(&clipboard, &Clipboard::dataRefreshed, this, &Tray::updateMenuList);
}

void Tray::updateMenuList(QList<QVariant> dataList)
{
//    static_assert(std::is_invocable_r<void, UnaryFunction, T>::value);

    auto actions = QList<QAction*>();
    for(auto& item: dataList) {
        auto action = new QAction(item.toString());
        connect(action, &QAction::triggered, this, [item, this](){
            clipboard.copy(item);
        });

        actions.push_back(action);
    }

    qDeleteAll(dataActions);
    dataActions = std::move(actions);

    renderMenu(menu, dataActions, controlActions);
}

Tray::~Tray(){
    qDeleteAll(dataActions);
    qDeleteAll(controlActions);

    delete menu;
    delete loginWin;
}

#include "moc_tray.cpp"
