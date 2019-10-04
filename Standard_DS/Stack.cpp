#include "Stack.h"

template <typename T>
Stack<T>::Stack(){
   pTop = nullptr;
   size = 0;
}

template <typename T>
Stack<T>::~Stack(){
   clear();
}

template <typename T>
void Stack<T>::push(const T& value){
   Node1<T>* pNew = new Node1<T>(value, pTop);
   pTop = pNew;
   ++size;
}

template <typename T>
void Stack<T>::pop(){
   if (!isEmpty()){
      Node1<T>* pTemp = pTop;
      pTop = pTop->pNext;
      delete pTemp;
      --size;
   }
}

template <typename T>
T& Stack<T>::top(){
   return pTop->value;
}

template <typename T>
int Stack<T>::getSize(){
   return size;
}

template <typename T>
bool Stack<T>::isEmpty(){
   return size == 0;
}

template <typename T>
bool Stack<T>::isFull(){
   Node1<T>* pNew = new Node1<T>();
   if (pNew == nullptr) return true;
   delete pNew;
   return false;
}

template <typename T>
void Stack<T>::clear(){
   while (size > 0){
      pop();  
   }
}
