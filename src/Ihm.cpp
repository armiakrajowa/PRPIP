#include <iostream>
#include <vector>

#include "Packet.hpp"

using namespace std;

vector<int> ihmNetwork(){
	vector<int> result;

	int response;
	int i = 0;

	cout << "Entrez la taille maximal des packets (0 pour terminer)" << endl;

	do {
		cout << "Reseau " << i + 1 << " : ";
		cin >> response;
		result.push_back(response);	
	} while (response == 0);

	i++;

	do {
		
		cout << "Reseau " << i + 1 << " : ";
		cin >> response;
		if (response != 0)
			result.push_back(response);
		i++;

	} while (response != 0);


	return result;
}

Packet ihmPacket(){
	cout << "Entrez la taille du paquet initial (en octet) : ";

	int response;
	cin >>response;

	Packet result;
	result.setMessageSize(response);

	return result;
}