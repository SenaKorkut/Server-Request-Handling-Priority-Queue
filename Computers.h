
/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : header file for server list
*/


#ifndef COMPUTERS_H_INCLUDED
#define COMPUTERS_H_INCLUDED

#include <string>
using namespace std;
#include "Request.h"

struct Computer {
    int timeLeft;
    bool available;

    Computer(){
		timeLeft = 0;
        available = true;
    }
};

class Computers{
public:
   Computers (int compCount);
	~Computers();
   void update();
   void process( Request* request, int currTime, string& displayData);
   int getWaitTotal();
   bool areAllBusy();
   bool areAllAvailable();

private:
    int compCount;
    Computer *computers;
    int waitTotal;
};


#endif // SERVERS_H_INCLUDED

