#include <iostream>
#include <cstring>

#define INIT_FLAG -1

using namespace std;

static int numOfSolutions = 0;

const int x[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int y[] = {0, -1, -2, -2, -1, 1, 2, 2, 1};

void KnightTravel(int ** board, int N, int row, int col, int index);
void PrintBoard(int ** board, int N);

void KnightTravel(int ** board, int N, int row, int col, int index){
   
   //if (numOfSolutions == 1) return;     
   
   for (int i = 0; i < 9; ++i){

      int r = row + x[i];
      int c = col + y[i];
      
      if (r >= 0 && r < N && c >= 0 && c < N && board[r][c] == INIT_FLAG){ 
         board[r][c] = index;
         if (index == N*N - 1){
            PrintBoard(board, N);
            ++numOfSolutions;
         }
         else KnightTravel(board, N, r, c, index + 1);
         board[r][c] = INIT_FLAG;
      }  
   }
}

void PrintBoard(int ** board, int N){
   for (int i = 0; i < N; ++i){
      for (int j = 0; j < N; ++j){
         cout << board[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

int main(int argc, char* argv[]){
   
   int N = stoi(argv[1]);
   
   int ** board;
   board = new int*[N];
   for (int i = 0; i < N; ++i)
      board[i] = new int[N];

   for (int i = 0; i < N; ++i){
      for (int j = 0; j < N; ++j){
         board[i][j] = INIT_FLAG;
      }
   }
   
   KnightTravel(board, N, 0, 0, 0);
   cout << "Number of solutions: " << numOfSolutions << endl;

   for (int i = 0; i < N; ++i)
      delete [] board[i];
   delete [] board;


   return 0;
}
