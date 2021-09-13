#include "Network.hpp"

#include <iostream>

using namespace std;

vector<Packet> Network::splitPacket(Packet p, int max_size, Packet previousPacket, bool prevPacket) {
	vector<Packet> result;

	Packet tempPacket;
	tempPacket.setMessageSize(p.getMessageSize());
	tempPacket.setOffset(p.getOffset());
	//TODO:skeggib Faire un constructeur par copie

	int max_message_size = ((max_size - tempPacket.getHeadSize() * 4)/ 8) * 8;

	int tempTaille;

	if(prevPacket){		
		tempTaille = (previousPacket.getOffset() * 8) + previousPacket.getMessageSize();
	}

	else {
		tempTaille = tempPacket.getOffset();
	}


	while(tempPacket.getMessageSize() != 0){

		cout << "DEBUG TAILLE: " << tempTaille << endl;

		Packet tempResult;

		if (tempPacket.getMessageSize() > max_message_size){
			tempResult.setMessageSize(max_message_size);
			tempResult.setOffset(tempTaille / 8);

			tempTaille += max_message_size;

			tempPacket.setMessageSize(tempPacket.getMessageSize() - max_message_size);
		}

		else {
			tempResult.setMessageSize(tempPacket.getMessageSize());
			tempResult.setOffset(tempTaille / 8);

			tempPacket.setMessageSize(0);
		}
		
		result.push_back(tempResult);
	}

	return result;
}

vector<Packet> Network::splitPackets(vector<Packet> p, int max_size) {
	vector<Packet> rtrn;
	vector<Packet> tempVector;

	for (int i = 0; i < p.size(); i++) {

		if(i == 0){
			tempVector = Network::splitPacket(p[i], max_size, p[i], false);
		}

		else {
			tempVector = Network::splitPacket(p[i], max_size, rtrn[rtrn.size() - 1], true);
		}

		rtrn.insert(rtrn.end(), tempVector.begin(), tempVector.end());
	}

	return rtrn;
}	