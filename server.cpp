#include <SFML/Network.hpp>
#include <iostream>
#include "common.h"

using namespace std;

int main(){
    cout << "Server\n";
    sf::TcpListener listener;
    if(listener.listen(WORKING_PORT)!= sf::Socket::Done){
        cout << "Cos poszlo nie tak\n";
    }

    sf::TcpSocket client;
    while(1){
        if(listener.accept(client) != sf::Socket::Done){
            cout << "Cos poszlo nie tak";
        }
        char data[100];
        size_t bytes_returned;
        if(client.receive(data,100,bytes_returned)!=sf::Socket::Done){
            cout << "Cos poszlo nie tak";
        }
        sf::IpAddress client_addr = client.getRemoteAddress();
        cout << "Otrzymana wiadomosc od <" << client_addr << "> " << data << endl;
        
    }
    return 0;
}