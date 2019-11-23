#ifndef DS_STACK
#define DS_STACK

template<typename T>
struct Node{
   T value;
   Node* pNext;

   Node(): pNext(nullptr){}
   Node(const T& val): value(val), pNext(nullptr){}
   Node(const T& val, Node* next) : value(val), pNext(next){}
};

template <typename T>
class Stack{
   
   int size;
   Node<T> *pTop;

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
   Node<T>* pNew = new Node<T>(value, pTop);
   pTop = pNew;
   ++size;
}

template <typename T>
void Stack<T>::pop(){
   if (!isEmpty()){
      Node<T>* pTemp = pTop;
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
   Node<T>* pNew = new Node<T>();
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

#endif
