#include <iostream>
#include <vector>

#include "Packet.hpp"

using namespace std;

vector<int> ihmNetwork(){
	vector<int> result;

	cout << "Entrez la valeur 0 pour confirmer" << endl;

	int response;

	cin >> response;
	while(response != 0){
		result.push_back(response);
		cin >> response;
	}


	return result;
}

Packet ihmPacket(){
	cout << "Entrez la taille du paquet initial (en octet)" << endl;

	int response;
	cin >>response;

	Packet result;
	result.setMessageSize(response);

	return result;
}