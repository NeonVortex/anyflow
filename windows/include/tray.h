#ifndef TRAY_H
#define TRAY_H

#include <functional>
#include <optional>
#include <memory>
#include <QtWidgets/QSystemTrayIcon>
#include <QAction>
#include "clipboard.h"
#include "loginwindow.h"

struct MenuItem
{
    QVariant data;
    std::optional<std::function<void(QVariant)>> action;
};

class Tray: public QWidget
{
    Q_OBJECT
public:
    Tray() = delete;
    Tray(const QString &filename, Clipboard &clipboard);
    virtual ~Tray();

    void updateMenuList(QList<QVariant> dataList);
private:
    Clipboard &clipboard;

    QMenu *menu;
    LoginWindow *loginWin;
    QList<QAction*> controlActions;
    QList<QAction*> dataActions;
};

#endif // TRAY_H
