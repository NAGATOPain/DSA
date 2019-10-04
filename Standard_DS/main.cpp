#include <iostream>
#include "Stack.h"

using namespace std;

int main(int argc, char* argv[]){
   
   Stack<int> s;
   s.push(1);
   s.push(2);
   s.push(3);

   while (!s.isEmpty()){
      cout << "Size of stack: " << s.getSize() << endl;
      cout << "Top of stack: " << s.top() << endl;
   
      s.pop(); 
   }

   return 0;
}
