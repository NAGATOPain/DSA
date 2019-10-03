template <typename T>
struct Node1{
   T value;
   Node1* pNext;

   Node1(): pNext(nullptr){}
   Node1(const T& val): value(val), pNext(nullptr){}
   Node1(const T& val, Node1* next): value(val), pNext(next){}
};

template <typename T>
struct Node2{
   T value;
   Node2* pNext;
   Node2* pPrev;

   Node2(): pNext(nullptr), pPrev(nullptr){}
   Node2(const T& val): value(val), pNext(nullptr), pPrev(nullptr){}
   Node2(const T& val, Node2* next, Node2* prev)
      : value(val), pNext(next), pPrev(prev){}
};




