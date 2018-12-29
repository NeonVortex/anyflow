#include <QtWidgets/QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QtGui/QIcon>
#include <memory>
#include "clipboardlistener.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto trayIcon = new QSystemTrayIcon(QIcon("tray-red.png"));
    trayIcon->setVisible(true);
//    trayIcon->showMessage("test1", "test2", QSystemTrayIcon::Information, 1000);

    ClipboardListener cl;

/*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;*/

    return app.exec();
}
