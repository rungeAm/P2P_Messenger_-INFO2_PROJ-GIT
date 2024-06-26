#pragma once

#include <iostream>
#include <string>
#include <WinSock2.h>
#include <ws2tcpip.h> //for InetPton
#include <sstream>
#include "Header.h"

//Winsock_Functions.cpp

int WSAStartup();
SOCKET createSocket();
sockaddr_in createSockaddr(SOCKET socket, std::string IP, int port);
int bindSocket(sockaddr_in sockaddr, SOCKET socket, std::string IP, int port);
int listen_(SOCKET socket, int max_connected);
SOCKET accept_(SOCKET socket);

int connect_(sockaddr_in sockaddr, SOCKET socket);
std::string recieve_(SOCKET socket);
int send_(SOCKET socket, std::string data);

//server.cpp

int ServerStartup(std::string IP, int PORT, float version);

//Client.cpp

int ClientStartup(std::string IP, int PORT, float version);
