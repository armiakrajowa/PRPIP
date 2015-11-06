#include <iostream>
#include "Packet.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    Packet test;

//    cout << test.totalSize() << endl; 

    test.setMessageSize(1300);
    vector<Packet> testV = test.split(1200);

    for(int i = 0; i < testV.size(); i++){
    	cout << "SIZE PACKET N" << (i + 1) << " : " << testV[i].totalSize() << endl;
    }

    return 0;
}
