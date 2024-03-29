/**
* Title : Heaps & AVL Trees
* Author : Sena Korkut
* ID: 21703303
* Section : 1
* Assignment : 3
* Description : implementation of heap
*/
#include "Heap.h"  // header file for class Heap

Heap::Heap() : size(0)
{
}  // end default constructor

Heap::~Heap()
{
}  // end destructor

bool Heap::heapIsEmpty() const{
   return bool(size == 0);
}  // end heapIsEmpty

void Heap::heapInsert(Request*& newItem){
   if (size < MAX_HEAP) {
   // place the new item at the end of the heap
   items[size] = newItem;

   // trickle new item up to its proper position
   int place = size;
   int parent = (place - 1)/2;
   while ( (parent >= 0) &&
           (items[place]->getPriority() > items[parent]->getPriority()) )
   {  // swap items[place] and items[parent]
      Request* temp = items[parent];
      items[parent] = items[place];
      items[place] = temp;

      place = parent;
      parent = (place - 1)/2;
   }  // end while

   ++size;
}  // end heapInsert
}

void Heap::heapDelete(Request*& rootItem){
   if (!heapIsEmpty())   {
	  rootItem = items[0];
      items[0] = items[--size];
      heapRebuild(0);
   }  // end if
}  // end heapDelete

void Heap::heapRebuild(int root)
{
   int child = 2 * root + 1;  // index of root's left
                              // child, if any
   if ( child < size )
   {  // root is not a leaf, so it has a left child at child
      int rightChild = child + 1;  // index of right child,
                                   // if any

      // if root has a right child, find larger child
      if ( (rightChild < size &&
           items[rightChild]->getPriority() > items[child]->getPriority()) ||  (items[rightChild]->getPriority() == items[child]->getPriority()
            && items[rightChild]->getRequestTime() < items[child]->getRequestTime()) )
         child = rightChild;  // index of larger child

      // if the root's value is smaller than the
      // value in the larger child, swap values
      if ( items[root]->getPriority() < items[child]->getPriority() || (items[root]->getPriority() == items[child]->getPriority()
            && items[root]->getRequestTime() > items[child]->getRequestTime()) )
      {  Request* temp = items[root];
         items[root] = items[child];
         items[child] = temp;


         // transform the new subtree into a heap
         heapRebuild(child);
      }  // end if
   }  // end if

   // if root is a leaf, do nothing
}  // end heapRebuild
// End of implementation file.
