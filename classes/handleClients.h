#include <vector>
#include <SFML/Network.hpp>
#include "common.h"

class handleClients{

private:
    struct client_data{
        sf::TcpSocket *socket;
        sf::IpAddress socket_addr;
    };
    
    std::vector<struct client_data> clients_sockets;
    size_t clients_count;
    sf::SocketSelector socket_group;

public:
    handleClients();
    ~handleClients();
    void add_client(sf::TcpSocket *socket);
    bool send_to_client(void *data, size_t data_size, struct client_data &c_data);
    bool send_to_all();
    bool wait_for_message();
    struct message_t recive_message(int *error);
};

