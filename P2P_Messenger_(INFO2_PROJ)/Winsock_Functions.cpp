//------------------------------------------------------------------
//LIBRARY SETUP
//------------------------------------------------------------------
#include <iostream>
#include <string>
#include <WinSock2.h>
#include <ws2tcpip.h> //for InetPton
#include <sstream>
#include "header.h"
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

using  std::endl;
using  std::cout;
using  std::cin;
using std::string;


int WSAStartup ()
{
	WSADATA wsaData;
	int wsaErr;
	WORD wVersionRequested = MAKEWORD(2, 2);

	wsaErr = WSAStartup(wVersionRequested, &wsaData);		

	if (wsaErr != 0)
	{
		cout << "wsaData connect error: " << wsaErr << endl;
		return -1;
	}
	else
	{
		(cout << "ws2_32.dll connected successfully!" << endl);
		return 0;
	}

}

SOCKET createSocket()
{

	return	socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	//(adress family (both udp and tcp), type (sockstream for tcp), protocol)


}

sockaddr_in createSockaddr(SOCKET socket, string IP, int port)
{
	sockaddr_in newSocket;
	newSocket.sin_family = AF_INET;
	newSocket.sin_port = htons(port);
	inet_pton(AF_INET, IP.c_str(), &newSocket.sin_addr.s_addr);

	return newSocket;
}

int bindSocket(sockaddr_in sockaddr, SOCKET socket, string IP, int port)
{
	

	if ((bind(socket, (SOCKADDR*)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR))
	{
		cout << "Binding server socket failed. Error: " << WSAGetLastError() << endl;
		closesocket(socket);
		WSACleanup();
		return -1;
	}
	else
	{
		cout << "bind successfull!" << endl;
		return 0;
	}

}

int listen_(SOCKET socket, int max_connected)
{
	if (listen(socket, max_connected) == SOCKET_ERROR)			//serverSocket , Amt of max connected servants
	{
		cout << "Listen failed. Error: " << WSAGetLastError() << endl;
		closesocket(socket);
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "listen successfull, waiting for connections.." << endl;
	}
}

SOCKET accept_(SOCKET socket)
{
	SOCKET acceptSocket;
	acceptSocket = accept(socket, NULL, NULL);

	if (acceptSocket == INVALID_SOCKET)
	{
		cout << "Accept failed, Error: " << WSAGetLastError() << endl;
		closesocket(socket);
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "Accept successful!" << endl;
		return acceptSocket;
	}

}

int connect_(sockaddr_in sockaddr, SOCKET socket)
{
	if ((connect(socket, (SOCKADDR*)&sockaddr, sizeof(sockaddr))) == SOCKET_ERROR)
	{
		cout << "connect failed. Error: " << WSAGetLastError() << endl;
		closesocket(socket);
		WSACleanup();
		return 0;
	}
	else
	{
		cout << "connection successfull!" << endl;
		return -1;
	}
}

std::string recieve_(SOCKET socket) 
{
	char dataBuffer[1024] = { 0 };

int Recv = recv(socket, dataBuffer, 1023, 0);

std::string message = dataBuffer;

if (Recv == 0)
{
	cout << "Recv Error: " << WSAGetLastError() << endl;
	closesocket(socket);
}
else

{
	cout << "Message recieved: " << dataBuffer << endl;

	return message;
}
}


int send_(SOCKET socket, std::string data)
{

	
	int Sent = send(socket, data.c_str(), data.length(), 0);
	cout << "trying to send!" << endl;

	if (Sent != 0)
	{
		cout << "send failed! Error:" << WSAGetLastError() << endl;
		return -1;
	}
	else if (Sent == 0)

	{
		cout << "send sucessfull! Sent Message: " << data << endl;
		return 0;
	}
}