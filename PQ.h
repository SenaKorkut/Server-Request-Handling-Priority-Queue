/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : header file for priority queue
*/


#ifndef PQ_H_INCLUDED
#define PQ_H_INCLUDED

#include "Heap.h"  // ADT heap operations
#include "Request.h"
/** @class PriorityQueue
 * ADT priority queue - Heap implementation. */
class PriorityQueue
{
public:
   // default constructor and copy constructor
   // are supplied by the compiler
   virtual ~PriorityQueue() {}

// priority-queue operations:
   virtual bool pqIsEmpty() const;
   virtual void pqInsert(Request*& newItem);
   virtual void pqDelete(Request*& priorityItem);

private:
   Heap h;
}; // end PriorityQueue

#endif // PQ_H_INCLUDED
