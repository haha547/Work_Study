#include <iostream>
#include <cmath>
#include "worker.hpp"
#include "machine.hpp"
#include "calculTime.hpp"
using namespace std;


int main() {
    
    calculTime calculOutput;
    float theCeil,theFloor;
    int machineNum[2];
    
    cout << "How many time worker operate need?";
    cin >> calculOutput.workerOperTime;
    cout << "How many time worker walking need?";
    cin >> calculOutput.workerWalkingTime;
    cout << "How many worker cost per hour?";
    cin >>calculOutput.workerCoastPerHour;

    cout << "How many time machine operate need?";
    cin >> calculOutput.machineOperTime;
    cout << "How many machine cost per hour?";
    cin >> calculOutput.machineCoastPerHour;

    
    calculOutput.LaddM = calculOutput.workerOperTime + calculOutput.machineOperTime;
    calculOutput.LaddW = calculOutput.workerOperTime + calculOutput.workerWalkingTime;
    
    theCeil = ceil(calculOutput.cycleTime());
    theFloor =  floor(calculOutput.cycleTime());

    machineNum[0] = int (theFloor);
    machineNum[1] = int (theCeil);

    

    cout << "Now you hve two opportunities" << endl << endl;
    cout << "First : One worker with " << machineNum[0] << " machines" << endl;
    cout << "Coast per item in " << machineNum[0] << " machines" << " is " << calculOutput.coastPerItem(machineNum[0]) << endl;
    cout << "The worker will idle " << calculOutput.workerIdle(machineNum[0]) <<" per cycle time";
    cout <<endl<<endl;


    cout << "Second : One worker with " << machineNum[1] << " machines" << " machines" << endl;
    cout << "Coast per item in " << machineNum[1] << " machines" << " is " << calculOutput.coastPerItem(machineNum[1]) << endl;
    cout << "The machines will idle " << calculOutput.machineIdle(machineNum[1]) <<" per cycle time";
    
    
    return 0;
}
