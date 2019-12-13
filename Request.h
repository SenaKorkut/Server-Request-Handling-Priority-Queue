/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : header file for request
*/


#ifndef REQUEST_H_INCLUDED
#define REQUEST_H_INCLUDED

#include <string>
using namespace std;

class Request{
public:
Request();

int getPriority() const;
void setPriority( int priority);
int getId() const;
void setId( int id );
int getRequestTime() const;
void setRequestTime( int requestTime );
int getProcessTime() const;
void setProcessTime( int processTime );

private:
   int id;
   int priority;
   int requestTime;
   int processTime;
};

#endif // REQUEST_H_INCLUDED
