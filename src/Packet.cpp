#include "Packet.hpp"

Packet::Packet() {
	this->head = 5;
	this->dont_fragment = false;
	this->more_fragment = false;
	this->message_size = 0;
	this->offset = 0;
}

Packet::~Packet() {

}

int Packet::totalSize() {
	// TODO
}

Vector<Packet> Packet::split(int max_size) {
	// TODO
}