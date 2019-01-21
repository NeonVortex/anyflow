#include <type_traits>
#include <QMenu>
#include <QMessageBox>
#include <QDebug>
#include "tray.h"

Tray::Tray(const QString &filename, Clipboard *clipboard):
    clipboard{clipboard},
    loginForm{new LoginForm()},
    controlActions{},
    dataActions{}
{
    auto loginAction = new QAction("Login");
    connect(loginAction, &QAction::triggered, this, [this](){
        loginForm->show();
    });

    auto aboutAction = new QAction("About");

    auto exitAction = new QAction("Exit");
    connect(exitAction, &QAction::triggered, this, [](){
        exit(0);
    });

    controlActions.push_back(loginAction);
    controlActions.push_back(aboutAction);
    controlActions.push_back(exitAction);

    auto loadingAction = new QAction("Syncing...");
    loadingAction->setEnabled(false);

    dataActions.push_back(loadingAction);

    menu = new QMenu();
    menu->setStyleSheet("QMenu {background: #373f49; color: #fff;}"
                        "QMenu::item:selected{background: #47505c;}"
                        "QMenu::item:disabled{background: #373f49; color: gray}");
//                        "QMenu::icon {background-color: black;}");
    menu->addActions(dataActions);
    menu->addSeparator();
    menu->addActions(controlActions);

    trayIcon = new QSystemTrayIcon(QIcon(filename), this);
//    trayIcon->setVisible(true);
//    trayIcon->showMessage("test1", "test2", QSystemTrayIcon::Information, 1000);
    trayIcon->setContextMenu(menu);
    connect(trayIcon, &QSystemTrayIcon::activated, [this](auto r){
        if (r == QSystemTrayIcon::ActivationReason::Trigger) {
            this->updateMenuList(QList<QVariant>{"test"}, [](auto r){
                qDebug() << r;
            });
        }
    });
}

template<typename T, typename F, typename>
void Tray::updateMenuList(QList<T> dataList, F f)
{
    auto actions = QList<QAction*>();
    for(auto& item: dataList) {
        auto action = new QAction(item.toString());
        connect(action, &QAction::triggered, this, [item, f](){
            f(item);
        });

        actions.push_back(action);
    }
    dataActions = std::move(actions);

    menu->clear();
    menu->addActions(dataActions);
    menu->addSeparator();
    menu->addActions(controlActions);
}

void Tray::show()
{
    this->trayIcon->show();
}

#include "moc_tray.cpp"
