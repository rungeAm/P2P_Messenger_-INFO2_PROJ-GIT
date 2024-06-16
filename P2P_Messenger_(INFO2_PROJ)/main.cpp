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

int PORT = 26000;
#define selfIP 127.0.0.1
#define IP1 192.168.1.102
std::string IP1s = "192.168.1.102";
std::string IP2s = "192.168.1.105";

//-----------------------------------------------------------------

int main()
{
	bool scs;
cout << "server or client? ";
cin >> scs;
if (scs)

	ClientStartup(IP1s, PORT);

else

	ServerStartup(IP1s, PORT);

	return 0;
}