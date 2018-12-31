#include <QtWidgets/QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QtGui/QIcon>
#include <memory>
#include "clipboard.h"
#include "tray.h"

int main(int argc, char *argv[])
{
    auto app = QApplication(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    Clipboard cl;
    Tray tray("tray-red.png", &cl);

/*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;*/

    return app.exec();
}
