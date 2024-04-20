#include<SocksServer/servers/TicTacToeServ/TicTacToeServer.h>
//#include<socks_serv/ThreadStorage.h>
//#include<socks_serv/Single.h>
//#include<socks_serv/AdminPanel.h>
//#include<SocksServer/servers/web_serv/src/WebServer.h>








/*
	"192.168.1.177"
	"127.0.0.1"

	192.168.1.177
	192.168.1.188
Ж
*/


int main()
{

	using SocksServer::GameServer::TicTacToeServer;
	/*using SocksServer::WebServer;*/
	using Socks::IPEndpoint;
	/*using SocksServer::threads::ThreadStorage;
	using SocksServer::Single;*/
	/*using for_admin::AdminPanel;*/

	TicTacToeServer server;



	server.init(IPEndpoint("192.168.1.177", 3000));
	server.init_rooms();
	server.listen_sock_fd();



	while (server.get_status() != ServerStatus::STOP)
		server.frame();

	/*Single::run(&server);
	ThreadStorage::thread_pool[0].join();*/


	/*TODO объявить сингл и кластер friend для сервера*/

	//AdminPanel panel;

	//panel.run(&server);
	/*только после того как сервер будет точно остановлен остановить всю систему*/

	

	

	/*WebServer server;


	server.init(IPEndpoint("192.168.1.177", 2000), true);

	while (server.get_status() != ServerStatus::STOP)
		server.frame();*/
}





//int main()
//{
//	
//	using SocksServer::GameServer::TicTacToeServer;
//	using Socks::IPEndpoint;
//
//
//
//	TicTacToeServer server;
//
//	server.init(IPEndpoint("192.168.1.177", 3000));
//	server.listen_sock_fd();
//	server.init_rooms();
//
//	
//	while (server.get_status() != ServerStatus::STOP)
//		server.frame();
//	
//
//
//
//	return 0;
//}