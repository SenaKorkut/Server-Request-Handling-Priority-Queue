
/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : main program to test
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

#include "Request.h"
#include "Computers.h"
#include "PQ.h"

void createRequests( string fileName, Request **&requests, int& reqNum );

int main(int argc, char *argv[]) {
    Request** requests;
    PriorityQueue pqueue;
    int maxAverage = atoi(argv[2]);
    int reqNum = 0;
	createRequests( argv[1], requests, reqNum );
    string toDisplay = "";
    double average = maxAverage + 1;

    int compCount = 1;
    while(average > maxAverage){
        Computers computers(compCount);
        toDisplay = "Minimum number of computers required: " + std::to_string(compCount) + "\nSimulation with " + std::to_string(compCount) + " computers:\n";
        int reqCount = 0;
        for(int time = 0; reqCount < reqNum || !computers.areAllAvailable() || !pqueue.pqIsEmpty(); time++) {
            while(   reqCount < reqNum  && (requests[reqCount])->getRequestTime() == time ){
                pqueue.pqInsert(requests[reqCount]);
                reqCount++;
            }
            while( !computers.areAllBusy() &&  !pqueue.pqIsEmpty()    ){
                Request *prior = NULL;
                pqueue.pqDelete( prior);

                if ( prior != NULL ){
                    computers.process(prior, time, toDisplay);
                }
            }
            computers.update();

        }
        average = (double)computers.getWaitTotal() /  reqNum;

        if(average <= maxAverage ){
            cout << toDisplay<< endl;
            cout << "Average waiting time: " << average << " ms. " << endl;
        }
        else{
            compCount++;
        }
    }
    return 0;
}

void createRequests( string fileName, Request**&requests, int& reqNum ){

	ifstream file(fileName);
	string line;
	getline(file, line);
	reqNum= atoi( line.c_str() );
	int count = 0;
	requests = new Request*[reqNum];

	while (getline(file, line)) {
		 Request *temp = new Request();
		 temp->setId( atoi( line.substr(0, line.find_first_of(" ")).c_str() ) );
		 line = line.substr(line.find_first_of(" ") + 1);
		 temp->setPriority( atoi( line.substr(0, line.find_first_of(" ")).c_str() ) );
		 line = line.substr(line.find_first_of(" ") + 1);
		 temp->setRequestTime( atoi( line.substr(0, line.find_first_of(" ")).c_str() ) );
         line = line.substr(line.find_first_of(" ") + 1);
         temp->setProcessTime( atoi( line.substr(0, line.find_first_of(" ")).c_str() ) );
		 requests[count++] = temp;
		}
	file.close();

    }


