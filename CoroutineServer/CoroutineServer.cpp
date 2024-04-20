#include<socks_serv/Socket.h>
#include<socks_serv/Net.h>
#include<coroutine>
#include <iostream>




std::coroutine_handle<> coro_handle;






int main()
{
    using namespace Socks;

    Net::initialize();

    Socks::Socket listener_socket;
    Socks::Socket accepted_socket;

    

    // Здесь можно добавить дополнительный код или ожидание завершения операции

    return 0;
    
    Net::shutdown();

}

