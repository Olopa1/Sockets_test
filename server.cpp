#include <SFML/Network.hpp>
#include <iostream>
#include "common.h"
#include <cstring>
#include <stdio.h>
#include <string>

using namespace std;

int main(){
    cout << "Server\n" /*<< sizeof(struct message_t) << "\n"*/;
    sf::TcpListener listener;
    if(listener.listen(WORKING_PORT)!= sf::Socket::Done){
        cout << "Cos poszlo nie tak\n";
    }

    sf::TcpSocket client;
    while(1){

        if(listener.accept(client) != sf::Socket::Done){
            cout << "Cos poszlo nie tak";
        }

        struct message_t recv_mess;
        size_t bytes_returned;
        if(client.receive(&recv_mess,sizeof(struct message_t),bytes_returned)!=sf::Socket::Done){
            cout << "Cos poszlo nie tak";
        }

        sf::IpAddress client_addr = client.getRemoteAddress();

        cout << "Otrzymana wiadomosc od <"<< recv_mess.user_name << "|" << client_addr << "> " << bytes_returned << endl;

        const char* server_message = "Wiadomosc otrzymana\n";
        if(client.send(server_message,strlen(server_message))!=sf::Socket::Done){
            cout << "Cos poszlo nie tak\n";
        }
        client.disconnect();
    }
    return 0;
}