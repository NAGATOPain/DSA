#ifndef DS_STACK
#define DS_STACK

#include "Node.h"

template <class T>
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

template <class T>
Stack<T>::Stack(){
   pTop = nullptr;
   size = 0;
}

template <class T>
Stack<T>::~Stack(){
   clear();
}

template <class T>
void Stack<T>::push(const T& value){
   Node1<T>* pNew = new Node1<T>(value, pTop);
   pTop = pNew;
   ++size;
}

template <class T>
void Stack<T>::pop(){
   if (!isEmpty()){
      Node1<T>* pTemp = pTop;
      pTop = pTop->pNext;
      delete pTemp;
      --size;
   }
}

template <class T>
T& Stack<T>::top(){
   return pTop->value;
}

template <class T>
int Stack<T>::getSize(){
   return size;
}

template <class T>
bool Stack<T>::isEmpty(){
   return size == 0;
}

template <class T>
bool Stack<T>::isFull(){
   Node1<T>* pNew = new Node1<T>();
   if (pNew == nullptr) return true;
   delete pNew;
   return false;
}

template <class T>
void Stack<T>::clear(){
   while (size > 0){
      pop();  
   }
}

#endif
