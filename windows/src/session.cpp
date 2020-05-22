#include "session.h"

Session::Session(Clipboard& cl):
    clipboard(cl)
{
    emit cl.dataRefreshed(QList<QVariant>{"test123"});
}
