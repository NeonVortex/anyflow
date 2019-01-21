#ifndef TRAY_H
#define TRAY_H

#include <functional>
#include <QtWidgets/QSystemTrayIcon>
#include <QAction>
#include "clipboard.h"
#include "loginform.h"

class Tray: public QObject
{
    Q_OBJECT
public:
    Tray() = delete;
    Tray(const QString &filename, Clipboard *clipboard);
public:
    template<typename T, typename F,
              typename = std::enable_if_t<std::is_invocable_v<F, T>>>
    void updateMenuList(QList<T> dataList, F f);
    void show();
private:
    Clipboard *clipboard;
    QMenu *menu;
    QSystemTrayIcon *trayIcon;
    LoginForm *loginForm;

    QList<QAction*> controlActions;
    QList<QAction*> dataActions;
};

#endif // TRAY_H
