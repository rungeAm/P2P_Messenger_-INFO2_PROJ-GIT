#include <iostream>
#include <string>
#include <WinSock2.h>
#include <ws2tcpip.h> //for InetPton
#include <sstream>
#include "Header.h"

#pragma comment(lib, "Ws2_32.lib")

using  std::endl;
using  std::cout;
using  std::cin;
using std::string;


//-----------------------------------------------------------------
int ClientStartup(std::string IP, int PORT, float version)
{
	//...................................................
	WSAStartup();

	//...................................................
	SOCKET clientSocket = INVALID_SOCKET;
	clientSocket = createSocket();

	if (clientSocket == INVALID_SOCKET)
	{
		cout << "Creating client socket gave error: " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "Client socket successfully created! Type: TCP" << endl;
	}

	//...................................................
	sockaddr_in clientSockaddr = createSockaddr(clientSocket, IP, PORT);

	connect_(clientSockaddr, clientSocket);

	//...................................................

	std::stringstream ss;
	string Sversion;
	ss << version;
	ss >> Sversion;

	string message = "INFO2 CONNECT/" + Sversion + "\n\n";
	message = "Hello WOrld!";

	//cout << "message to send: " << message;

	send_(clientSocket, message);
}