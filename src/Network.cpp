#include "Network.hpp"

vector<Packet> Network::splitPacket(Packet p, int max_size) {
	vector<Packet> result;

	Packet tempPacket;
	tempPacket.setMessageSize(p.getMessageSize());
	//TODO:skeggib Faire un constructeur par copie

	int max_message_size = ((max_size - tempPacket.getHeadSize * 4)/ 8) * 8;

	cout <<  "MAX SIZE = " << max_message_size << endl; // TODO a enlever

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