//------------------------------------------------------------------
//LIBRARY SETUP
//------------------------------------------------------------------
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

int ServerStartup(std::string IP, int PORT)
{
	//...................................................
	WSAStartup();

	//...................................................
	SOCKET serverSocket = INVALID_SOCKET;
	serverSocket = createSocket();

	if (serverSocket == INVALID_SOCKET)
	{
		cout << "Creating server socket gave error: " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "Server socket successfully created! Type: TCP" << endl;
	}

	//...................................................
	sockaddr_in serverSockaddr = createSockaddr(serverSocket, IP, PORT);
	bindSocket(serverSockaddr,serverSocket, IP, PORT);

	//...................................................
	listen_(serverSocket, 10);

	//...................................................
	accept_(serverSocket);

	//...................................................
	string message = recieve_(serverSocket);
	cout << "Message: " << message << endl;


	//...................................................

	return 0;
}
