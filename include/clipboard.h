#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QObject>
#include <QVariant>

class Clipboard: public QObject
{
    Q_OBJECT
public:
    Clipboard();
    void copy(QVariant);
signals:
    void onDataRefresh(QList<QVariant>);
};

#endif // CLIPBOARD_H
