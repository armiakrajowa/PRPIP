#include "Packet.hpp"

Packet::Packet() {
	this->head_size = 5;
	this->dont_fragment = false;
	this->more_fragment = false;
	this->message_size = 0;
	this->offset = 0;
}

Packet::~Packet() {

}

int Packet::totalSize() {
	return (this->message_size + (this->head_size * 4));
}

void  Packet::setMessageSize(int message_size) {
	this->message_size = message_size;
}

void  Packet::setOffset(int offset) {
	this->offset = offset;
}

vector<Packet> Packet::split(int max_size) {
	
	vector<Packet> result;



	// Packet tempP;
	// tempP.setMessageSize(this->message_size);
	// //TODO:sleggib Faire un constructeur par copie

	// while(tempP->message_size != 0){

	// }


	// int message_size_last_packet = this->message_size % max_size;
	// int nombre_packet_entier = (this->message_size - message_size_last_packet) / max_size;

	// Packet test;
	// test.setMessageSize(max_size);

	// result.push_back(test);

	// test.setMessageSize(300);

	// result.push_back(test);

	return result;
}




