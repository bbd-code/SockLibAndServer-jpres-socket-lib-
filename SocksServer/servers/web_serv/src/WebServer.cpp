#include "WebServer.h"


namespace SocksServer
{

	ServerStatus WebServer::on_connect(Socket& connection)
	{

		
		
		recv_n_check_buffer(connection);
		
		return send_response(connection);

	}

	ServerStatus WebServer::send_response(SocksServer::Server::Socket& connection)
	{

		std::string content = "404 Not Found";
		try
		{
			reader.open("servers/web_serv/res/index.htm");

			content.clear();

			if (reader.good())
			{
				std::string tmp((std::istreambuf_iterator<char>(reader)), std::istreambuf_iterator<char>());
				content = tmp;

			}

		}
		catch (FileReader::failure::exception& ex)
		{
			std::cout << ex.what() << std::endl;
			reader.close();
			return ServerStatus::_ERROR;
		}

		Buffer response_buffer;
		response_buffer << "HTTP/1.1 200 OK\r\n";
		response_buffer << "Cache-Control: no-cache, private\r\n";
		response_buffer << "Content-Type: text/html\r\n";
		response_buffer << "Content-Length: " << content.size() << "\r\n";
		response_buffer << "\r\n";
		response_buffer << content;

		std::string response = response_buffer.str();

		

		connection.st_send(response);


		reader.close();

		return ServerStatus::OK;
	}

	ServerStatus WebServer::on_disconnect(Socket& connection)
	{
		if (connection.st_close() == SR::GENERIC_ERROR)
			return ServerStatus::_ERROR;
		return ServerStatus::OK;
	}

	ServerStatus WebServer::close_conn(Socket& connection)
	{
		return ServerStatus();
	}

	ServerStatus WebServer::recv_n_check_buffer(Socket& connection)
	{
		connection.st_recieve(buffer);
		if (buffer.size() == 0)
			return ServerStatus::_ERROR;
		else if (buffer.size() > Socks::_const::max_packet_size)
			return ServerStatus::_ERROR;

		return ServerStatus::OK;
	}


	/*ServerStatus WebServer::on_disconnect(Socket& connection)
	{
		
	}
	


	ServerStatus WebServer::close_conn(Socket& connection)
	{
	}*/



	void WebServer::frame()
	{
		Socket new_conn;

		if (listening_socket.st_accept(new_conn) == SR::OK)
		{
			status = on_connect(new_conn);
			status = on_disconnect(new_conn);
		}

	}

}