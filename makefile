all : compile_server compile_client

compile_server:
	g++ -c server.cpp
	g++ server.o -o server.exe -lsfml-network

compile_client:
	g++ -c client.cpp
	g++ client.o -o client.exe -lsfml-network -lsfml-system

