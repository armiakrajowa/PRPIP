#include "Packet.hpp"
#include <iostream>

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

int Packet::getMessageSize(){
	return this->message_size;
}

int Packet::getHeadSize(){
	return this->head_size;
}

vector<Packet> Packet::split(int max_size) {
	
	vector<Packet> result;


	Packet tempP;
	tempP.setMessageSize(this->message_size);
	//TODO:sleggib Faire un constructeur par copie

	int max_message_size = ((max_size - tempP.head_size * 4)/ 8) * 8;

	cout <<  "MAX SIZE = " << max_message_size << endl;

	while(tempP.message_size != 0){
		Packet resTemp;

		if(tempP.message_size > max_message_size){
			resTemp.message_size = max_message_size;
			tempP.message_size -= max_message_size;
		} else {
			resTemp.message_size = tempP.message_size;
			tempP.message_size = 0;
		}
		result.push_back(resTemp);
	}
	return result;
}




