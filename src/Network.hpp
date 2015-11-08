#pragma once

#include "Packet.hpp"

#include <vector>

using namespace std;

class Network
{

public:
	static vector<Packet> splitPacket(Packet p, int max_size, Packet previousPacket, bool prevPacket);
	static vector<Packet> splitPackets(vector<Packet> p, int max_size);

};