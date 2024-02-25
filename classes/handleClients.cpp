#include "handleClients.h"
#include <iostream>

handleClients::handleClients(){
    this->clients_count = 0;
}

handleClients::~handleClients(){
    for(int i =0; i < this->clients_count;i++){
        (this->clients_sockets[i].socket)->disconnect();
    }
    socket_group.clear();
}

void handleClients::add_client(sf::TcpSocket *socket){
    this->clients_count ++;
    struct client_data new_client;
    new_client.socket = socket;
    new_client.socket_addr = new_client.socket->getRemoteAddress();
    this->socket_group.add(*socket);
    this->clients_sockets.push_back(new_client);
}

void handleClients::client_disconnect(){}

bool handleClients::send_to_client(void *data, size_t data_size,const struct client_data &reciver){
    if(data == nullptr){
        return false;
    }
    if(reciver.socket->send(data,data_size) != sf::Socket::Done){
        std::cout << "Wysylanie wiadomosci nie powidolo sie";
        return false;
    }
    std::cout << "Wyslano " << data_size << "bajtow do <" << reciver.client_name << "|" << reciver.socket_addr << ">\n";
    return true;
}

bool handleClients::send_to_all(void *data, size_t data_size){
    if(data == nullptr){
        return false;
    }
    for(int i = 0 ; i < this->clients_count;i++){
        if(this->clients_sockets[i].socket->send(data,data_size)!=sf::Socket::Done){
            std::cout << "Wysylanie nie powiodlo sie\n";
            return false;
        }
    }
    std::cout << "Wyslano do wszystkich\n";
    return true;
}

bool handleClients::wait_for_message(){
    sf::Time time_out = sf::seconds(10.0f);
    if(this->socket_group.wait(time_out)){
        return true;
    }
    return false;
}

int handleClients::recive_message(void* buffor,size_t buff_size,size_t data_recived){
    for(int i = 0 ; i < this->clients_count;i++){
        if(this->socket_group.isReady(*(this->clients_sockets[i].socket))){
            if(this->clients_sockets[i].socket->receive(buffor,buff_size,data_recived)!=sf::Socket::Done){
                std::cout << "Nie udalo odebrac sie danych\n";
                return -1;
            }
            else{
                return i;
            }
        }
    }
    return -1;
}

void handleClients::print_message(struct message_t &message, int index){
    std::cout << "Otrzymana wiadomosc od <"<< message.user_name << "|" << this->clients_sockets[index].socket_addr << "> " << message.message << std::endl;
}