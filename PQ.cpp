/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : implementation of priority queue
*/
#include "PQ.h"    // header file for priority queue

bool PriorityQueue::pqIsEmpty() const
{
   return h.heapIsEmpty();
}  // end pqIsEmpty

void PriorityQueue::pqInsert(Request*& newItem)
{
      h.heapInsert(newItem);
}  // end pqInsert

void PriorityQueue::pqDelete(Request*& priorityItem)
{
   if( !pqIsEmpty() )
   {
      h.heapDelete(priorityItem);
   }  // end try
}  // end pqDelete
