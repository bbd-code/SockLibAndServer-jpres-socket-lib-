#pragma once



#ifndef CONSOLE_SERVER_H
#define CONSOLE_SERVER_H


#include<socks_serv/Server.h>




namespace SocksServer
{

	class ConsoleServer : public Server
	{

	public:
		

		void frame() override;

	private:


		
		ServerStatus on_connect(Socket& connection) override;
		ServerStatus on_disconnect(Socket& connection) override;
		ServerStatus close_conn(Socket& connection) override;

	private:
		std::string buffer;
	};

}

#endif // !CONSOLE_SERVER_H