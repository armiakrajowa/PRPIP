#include <iostream>
#include "Packet.hpp"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

    Packet test;

//    cout << test.totalSize() << endl; 

    vector<Packet> testV = test.split(1200);

    for(int i = 0; i < testV.size(); i++){
    	cout << testV[i].totalSize() << endl;
    }

    return 0;
}
