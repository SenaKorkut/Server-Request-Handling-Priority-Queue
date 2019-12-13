/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : implementation of server list
*/

#include <string>
#include <iostream>
#include <sstream>
using namespace std;

#include "Request.h"
#include "Computers.h"


Computers::Computers(int compCount){
	this->compCount = compCount;
	computers = new Computer[compCount];
    waitTotal = 0;
}
Computers:: ~Computers() {
 }

void Computers::update(){
    for(int i = 0; i < compCount; i++){
        if( !computers[i].available && --computers[i].timeLeft <= 0) {
				computers[i].timeLeft = 0;
                computers[i].available = true;
        }
    }
}

void Computers::process( Request* request, int currTime, string& toDisplay ){
    bool ctrl = false;
    for(int i = 0; i < compCount && ctrl == false; i++ ){
        if( computers[i].available){
			toDisplay += "Computer " + std::to_string(i) + " takes request "
                    + std::to_string( request->getId()) + " at ms " + std::to_string( currTime)
                    + " (wait: " +std::to_string( currTime - request->getRequestTime() )
                    + " ms)\n";

			computers[i].available = false;
			computers[i].timeLeft = request->getProcessTime();
			waitTotal += currTime - request->getRequestTime();
			ctrl = true;;
        }
    }
}


int Computers::getWaitTotal() {
	return waitTotal;
}


bool Computers::areAllBusy(){
    bool ctrl = true;
    for (int i = 0; i < compCount; i++){
        if( computers[i].available ){
            ctrl = false;
        }
    }
    return ctrl;
}

bool Computers::areAllAvailable(){
    bool ctrl = true;
    for(int i = 0; i < compCount; i++){
        if( !computers[i].available ){
            ctrl = false;
        }
    }
    return ctrl;
}
