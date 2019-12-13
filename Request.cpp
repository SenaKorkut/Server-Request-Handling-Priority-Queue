/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : a class for requests of each txt line
*/


#include <iostream>
using namespace std;

#include "Request.h"

Request::Request(){

	id = -1;
	priority = -1;
    requestTime = -1;
    processTime = -1;
}

int Request::getPriority() const{
	return priority;
}
int Request::getId() const{
	return id;
}
int Request::getRequestTime() const{
	return requestTime;
}
int Request::getProcessTime() const{
	return processTime;
}
void Request::setPriority( int priority ) {
	this->priority = priority;
	}
void Request::setId( int id ) {
	this->id = id;
}
void Request::setRequestTime( int requestTime ) {
	this->requestTime = requestTime;
}
void Request::setProcessTime( int processTime ) {
	this->processTime = processTime;
}
