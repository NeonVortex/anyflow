#include <QtWidgets/QApplication>
#include <QtWidgets/QSystemTrayIcon>
#include <QtGui/QIcon>
#include <memory>
#include "clipboard.h"
#include "tray.h"
#include "remoteservice.h"

int main(int argc, char *argv[])
{
    auto app = QApplication(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    auto cl = Clipboard{};
    auto tray = Tray("tray-red.png", &cl);

    auto service = RemoteService{};

    tray.show();

    return app.exec();
}
