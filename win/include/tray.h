#ifndef TRAY_H
#define TRAY_H

#include <functional>
#include <QtWidgets/QSystemTrayIcon>
#include <QAction>
#include "clipboard.h"

class Tray: public QObject
{
    Q_OBJECT
public:
    Tray() = delete;
    Tray(const QString &filename, Clipboard *clipboard);
public:
    template<typename T, typename F,
             typename = std::enable_if<std::is_invocable<F, T>::value>>
    void updateMenuList(QList<T> dataList, F f);
    void show();
private:
    Clipboard *clipboard;
    QMenu *menu;
    QSystemTrayIcon *trayIcon;
    QList<QAction*> controlActions;
    QList<QAction*> dataActions;
};

#endif // TRAY_H
