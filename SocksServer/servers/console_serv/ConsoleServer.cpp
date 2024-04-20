#include "ConsoleServer.h"


namespace SocksServer
{

    void ConsoleServer::frame()
    {
    }

    ServerStatus ConsoleServer::on_connect(Socket& connection)
    {
        return ServerStatus();
    }

    ServerStatus ConsoleServer::on_disconnect(Socket& connection)
    {
        return ServerStatus();
    }

    ServerStatus ConsoleServer::close_conn(Socket& connection)
    {
        return ServerStatus();
    }

}