#include <iostream>
#include <cstring>

#define DEATH_FLAG 1 
#define INIT_FLAG 0

using namespace std;

static int numOfSolutions = 0;

bool isValidPosition(int ** board, int N, int row, int col);
void SolveNQueensProblem(int ** board, int N, int row);
void PrintBoard(int ** board, int N);

bool isValidPosition(int ** board, int N, int row, int col){
   for (int i = 0; i < N; ++i){
      if (board[row][i] == DEATH_FLAG && i != col) return false;
      if (board[i][col] == DEATH_FLAG && i != row) return false;
      if (row - i - 1 >= 0 && row - i - 1 < N && 
          col - i - 1 >= 0 && col - i - 1 < N && 
          board[row - i - 1][col - i - 1] == DEATH_FLAG) return false;
      if (row + i + 1 >= 0 && row + i + 1 < N && 
          col + i + 1 >= 0 && col + i + 1 < N && 
          board[row + i + 1][col + i + 1] == DEATH_FLAG) return false;
      if (row - i - 1 >= 0 && row - i - 1 < N && 
          col + i + 1 >= 0 && col + i + 1 < N && 
          board[row - i - 1][col + i + 1] == DEATH_FLAG) return false;
      if (row + i + 1 >= 0 && row + i + 1 < N && 
          col - i - 1 >= 0 && col - i - 1 < N && 
          board[row + i + 1][col - i - 1] == DEATH_FLAG) return false;
   }
   return true;
}

void SolveNQueensProblem(int ** board, int N, int row){
   
   // End after getting a solutions
   if (numOfSolutions == 1) return;

   for (int col = 0; col < N; ++col){
      if (isValidPosition(board, N, row, col)){
         board[row][col] = DEATH_FLAG;
         if (row < N - 1){
            SolveNQueensProblem(board, N, row + 1);
         }
         else { 
            PrintBoard(board, N);     
            ++numOfSolutions;
         }
         board[row][col] = INIT_FLAG;
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

   int ** board = new int*[N];
   for (int i = 0; i < N; ++i)
      board[i] = new int[N];

   for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
         board[i][j] = INIT_FLAG;
   
   SolveNQueensProblem(board, N, 0);
   
   cout << "Number of solutions: " << numOfSolutions << endl;

   for (int i = 0; i < N; ++i)
      delete [] board[i];
   delete [] board;
   
   return 0;
}
