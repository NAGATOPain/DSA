#ifndef DS_STACK
#define DS_STACK

#include "Node.h"

template <typename T>
class Stack{
   
   int size;
   Node1<T> *pTop;

public:
   Stack();
   ~Stack();
   
   void push(const T& value);
   void pop();
   T& top();

   int getSize();
   bool isEmpty();
   bool isFull();

   void clear();
};

#endif
