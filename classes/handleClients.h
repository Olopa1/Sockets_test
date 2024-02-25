#include <vector>
#include <SFML/Network.hpp>
#include "common.h"

class handleClients{

private:
    struct client_data{
        char client_name[20];
        sf::TcpSocket *socket;
        sf::IpAddress socket_addr;
    };
    
    std::vector<struct client_data> clients_sockets;
    int clients_count;
    sf::SocketSelector socket_group;

public:
    handleClients();
    ~handleClients();
    void add_client(sf::TcpSocket *socket);
    bool send_to_client(void *data, size_t data_size,const struct client_data &reciver);
    bool send_to_all(void *data, size_t data_size);
    bool wait_for_message();
    int recive_message(void* buffor,size_t buff_size,size_t data_recived);
    void client_disconnect();
    void print_message(struct message_t &message, int index);
};

