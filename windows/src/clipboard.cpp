#include <QDebug>
#include "clipboard.h"

Clipboard::Clipboard()
{

}

void Clipboard::copy(QVariant data)
{
    qDebug() << "Copied" << data;
}

#include "moc_clipboard.cpp"