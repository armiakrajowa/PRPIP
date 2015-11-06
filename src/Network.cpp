#include "Network.hpp"

#include <iostream>

using namespace std;

vector<Packet> Network::splitPacket(Packet p, int max_size) {
	vector<Packet> result;

	Packet tempPacket;
	tempPacket.setMessageSize(p.getMessageSize());
	//TODO:skeggib Faire un constructeur par copie

	int max_message_size = ((max_size - tempPacket.getHeadSize() * 4)/ 8) * 8;

	while(tempPacket.getMessageSize() != 0){
		Packet tempResults;

		if (tempPacket.getMessageSize() > max_message_size){
			tempResults.setMessageSize(max_message_size);
			tempPacket.setMessageSize(tempPacket.getMessageSize() - max_message_size);
		}

		else {
			tempResults.setMessageSize(tempPacket.getMessageSize());
			tempPacket.setMessageSize(0);
		}
		
		result.push_back(tempResults);
	}

	return result;
}

vector<Packet> Network::splitPackets(vector<Packet> p, int max_size) {
	vector<Packet> rtrn;
	vector<Packet> tempVector;

	for (int i = 0; i < p.size(); i++) {
		tempVector = Network::splitPacket(p[i], max_size);
		rtrn.insert(rtrn.end(), tempVector.begin(), tempVector.end());
	}

	return rtrn;
}