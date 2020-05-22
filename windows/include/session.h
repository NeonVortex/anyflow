#ifndef SESSION_H
#define SESSION_H

#include "clipboard.h"

class Session
{
public:
    Session() = delete;
    Session(Clipboard& cl);

private:
    Clipboard& clipboard;
};

#endif // SESSION_H
