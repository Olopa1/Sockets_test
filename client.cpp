#include <SFML/Network.hpp>
#include <iostream>
#include "common.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main(){
    cout << "Client running\n";
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(SERVER_IP,WORKING_PORT);
    if(status != sf::Socket::Done){
        cout << "Cos poszlo nie tak\n";
    }
    char server_res[100];
    size_t response_size;
    struct message_t mess;
    
    cout << "Podaj nazwe uzytkownika:\n";
    scanf("%20[^\n]",mess.user_name);
    cout << "\nPodaj wiadomosc maks 1024 znaki:\n";
    scanf("%1023[^\n]",mess.message);

    if(socket.send(&mess,sizeof(struct message_t))!= sf::Socket::Done){
        cout << "Cos poszlo nie tak\n";
    }

    if(socket.receive(server_res,100,response_size)!=sf::Socket::Done){
        cout << "Cos poszlo nie tak";
    }
    cout << "Odpowiedz servera: " << server_res;
    return 0;
}