#include "handleClients.h"

handleClients::handleClients(){
    this->clients_count = 0;
}

handleClients::~handleClients(){
    for(int i =0; i < this->clients_count;i++){
        //*(clients_sockets[i].socket).disconnect();
        (this->clients_sockets[i].socket)->disconnect();
    }
    socket_group.clear();
}

void handleClients::add_client(sf::TcpSocket *socket){
    this->clients_count ++;
    struct client_data new_client;
    new_client.socket = socket;
    new_client.socket_addr = new_client.socket->getRemoteAddress();
}

bool handleClients::send_to_client(void *data, size_t data_size, struct client_data &c_data){}
bool handleClients::send_to_all(){}
bool handleClients::wait_for_message(){}
struct message_t handleClients::recive_message(int *error){}