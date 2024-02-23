#include <SFML/Network.hpp>
#include <iostream>
#include "common.h"
#include <string.h>
#include <unistd.h>
using namespace std;

int main(){
    cout << "Client running\n";
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect(SERVER_IP,WORKING_PORT);
    if(status != sf::Socket::Done){
        cout << "Cos poszlo nie tak\n";
    }

    const char *data = "Tekst z klienta";
    for (size_t i = 0; i < 10; i++)
    {    
        sleep(2);
        if(socket.send(data,strlen(data))!= sf::Socket::Done){
            cout << "Cos poszlo nie tak\n";
        }

    }

    return 0;
}