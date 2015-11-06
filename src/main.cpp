#include <iostream>
#include <vector>

#include "Packet.hpp"
#include "Network.hpp"
#include "Ihm.hpp"

using namespace std;

int main(int argc, char* argv[]) {



	ihmNetwork();

	ihmPacket();

    Packet test;
    test.setMessageSize(1300);
    vector<Packet> testV = Network::splitPacket(test, 1200);

    for(int i = 0; i < testV.size(); i++){
    	cout << "Total (" << (i + 1) << ") = " << testV[i].totalSize();
    	cout << " Message = " << testV[i].getMessageSize();
    	cout << " Head = " << testV[i].getHeadSize() << endl;
    }

    return 0;
}