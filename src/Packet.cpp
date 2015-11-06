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
