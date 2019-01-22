#ifndef REMOTESERVICE_H
#define REMOTESERVICE_H

#include <asio.hpp>

class RemoteService
{
public:
    RemoteService();
private:
    asio::io_context ioContext;
    asio::ip::tcp::resolver resolver;
};

#endif // REMOTESERVICE_H
