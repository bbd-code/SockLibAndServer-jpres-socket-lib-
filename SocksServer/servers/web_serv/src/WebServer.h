#pragma once


#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include<socks_serv/Server.h>
#include<fstream>
#include<sstream>

namespace SocksServer {


	class WebServer : public Server
	{
		using FileReader = std::ifstream;
		using FileWriter = std::ofstream;
		using Buffer = std::ostringstream;

	public:

		void frame() override;

	protected:
		ServerStatus on_connect(Socket& connection) override;
		ServerStatus send_response(SocksServer::Server::Socket& connection);
		ServerStatus on_disconnect(Socket& connection) override;
		ServerStatus close_conn(Socket& connection) override;

	private:
		ServerStatus recv_n_check_buffer(Socket& connection);

	private:
		FileReader reader;
		FileWriter writer;

	

	};


}
#endif // !HTTP_SERVER_H