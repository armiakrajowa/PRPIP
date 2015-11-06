#include <iostream>
#include <vector>

#include "Packet.hpp"
#include "Network.hpp"

using namespace std;

void displayPacketsVector(vector<Packet> vec);

int main(int argc, char* argv[]) {

    Packet packet;

//    cout << packet.totalSize() << endl; 

    packet.setMessageSize(1300);

    vector<Packet> vec = Network::splitPacket(packet, 1200);

    displayPacketsVector(vec);

    cout << endl;

    vec = Network::splitPackets(vec, 1100);

    displayPacketsVector(vec);

    return 0;
}

void displayPacketsVector(vector<Packet> vec) {
	for(int i = 0; i < vec.size(); i++){
    	cout << "Total (" << (i + 1) << ") = " << vec[i].totalSize();
    	cout << " Message = " << vec[i].getMessageSize();
    	cout << " Head = " << vec[i].getHeadSize() << endl;
    }
}
