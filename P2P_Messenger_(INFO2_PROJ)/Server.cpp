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

int ServerStartup(std::string IP, int PORT, float version)
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
	


	//...................................................
	
		listen_(serverSocket, 10);
		SOCKET acceptSocket = accept_(serverSocket);
		string recieved = recieve_(acceptSocket);
		cout << "recieved: " << recieved;

		//...................................................
		/*char buffer[1024] = "";
		

		string ConnectResponse = recieve_(acceptSocket);
		cout << "test1!" << endl;
		if (!(strcmp(ConnectResponse.c_str(), "INFO2 CONNECT/")))
		{
			cout << "recieved Connection attempt" << endl;

			std::stringstream ss2;
			string responseVers(buffer + 14);
			ss2 << responseVers;
			double clientVersion;
			ss2 >> clientVersion;
			cout << "test2!" << endl;
			if (clientVersion >= version)
			{
				std::cout << "handshake successful\n";
				std::string acceptConnection = "INFO2 OK\n\n";

				send(acceptSocket, acceptConnection.c_str(), acceptConnection.length(), 0);
				cout << "responds with INFO2 OK! " << endl;
				closesocket(acceptSocket);
			}
			else
			{
				std::cout << "handshake failed" << endl;
				continue;
			}

		}
		*/
	


	//...................................................

	return 0;
}
