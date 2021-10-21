//Akulkumar Patel
//CS 280, 450
//NJIT-ID: 31504835

#include<iostream>
#include<iomanip>
using namespace std;
const int N = 8;

typedef struct chess_moves {
    int x,y;
    }chess_moves;

void printKT(int tour[N][N]) {
   int i,j;
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
          cout<<setw(3)<<tour[i][j]+1;
      }
      cout<<endl;
   }
}

bool movePossible(chess_moves next_move, int tour[N][N]) {
   int i = next_move.x;
   int j = next_move.y;
   if ((i >= 0 && i < N) && (j >= 0 && j < N) && (tour[i][j] == 0))
      return true;
   return false;
}

bool findTour(int tour[N][N], chess_moves move_KT[],
               chess_moves curr_move, int move_count)
    {
        int i;
        chess_moves next_move;
        if (move_count == N*N-1)
            {
                return true;
            }

       for (i = 0; i < N; i++)
        {
          next_move.x = curr_move.x + move_KT[i].x;
          next_move.y = curr_move.y + move_KT[i].y;
          if (movePossible(next_move, tour))
          {
             tour[next_move.x][next_move.y] = move_count+1;
             if (findTour(tour, move_KT, next_move, move_count+1) == true)
                return true;
             else
                tour[next_move.x][next_move.y] = 0;
          }
        }
        return false;
    }

void knightTours()
{
   int tour[N][N];
   int i,j;
   for (i = 0; i < N; i++)
    {
      for (j = 0; j < N; j++)
      {
         tour[i][j] = 0;
      }
    }

   chess_moves move_KT[8] = { {2,1},{1,2},{-1,2},{-2,1},
                                {-2,-1},{-1,-2},{1,-2},{2,-1} };

   chess_moves curr_move = {0,0};

   if(findTour(tour, move_KT, curr_move, 0) == false)
    {
      cout<<"Knights tour does not exist";
    }
   else
   {
      cout<<"Knights Tour exists...\n";
      printKT(tour);
   }
}

int main()
{
   knightTours();
   cout<<endl;
   return 0;
}
