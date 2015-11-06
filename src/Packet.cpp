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

vector<Packet> Packet::split(int max_size) {
	// TODO
}