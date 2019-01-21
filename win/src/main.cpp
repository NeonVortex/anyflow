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

    tray.show();

    return app.exec();
}
