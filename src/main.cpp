#include <iostream>
#include <vector>

#include "Packet.hpp"
#include "Network.hpp"
#include "Ihm.hpp"

using namespace std;

void displayPacketsVector(vector<Packet> vec);

int main(int argc, char* argv[]) {
    
    Packet packet = ihmPacket();
    cout << endl;
    vector<int> networksSizes = ihmNetwork();

    int i = 0;
    vector<Packet> vectorPacket = Network::splitPacket(packet, networksSizes[0]);
    cout << endl << endl << "Reseau " << i + 1 << endl;
    displayPacketsVector(vectorPacket);
    i++;

    while (i < networksSizes.size()) {
        vectorPacket = Network::splitPackets(vectorPacket, networksSizes[i]);
        cout << endl << endl << "Reseau " << i + 1 << endl;
        displayPacketsVector(vectorPacket);
        i++;
    }

    return 0;
}

void displayPacketsVector(vector<Packet> vec) {
	for(int i = 0; i < vec.size(); i++){
    	cout << "(" << (i + 1) << ")";
        cout << "\tTotal = " << vec[i].totalSize();
    	cout << "\tMessage = " << vec[i].getMessageSize();
    	cout << "\tHead = " << vec[i].getHeadSize() << endl;
    }
}
