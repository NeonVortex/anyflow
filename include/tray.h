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
    template<typename T, typename UnaryFunction>
    void updateMenuList(QList<T> dataList, UnaryFunction f);
private:
    Clipboard *clipboard;
    QMenu *menu;
    QList<QAction*> *controlActions;
    QList<QAction*> *dataActions;
};

#endif // TRAY_H
