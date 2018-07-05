// Example program
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> GenerateMap(int H, int W, int M) {
        int n = M;
        vector<int> width(W+2, 0);
        vector<vector<int>> board(H+2, width);
        while(n>0) {
            int posx = rand()%W+1, posy = rand()%H+1;
            while(board[posy][posx]!=0) {
                posx = rand()%W+1;
                posy = rand()%H+1;
            }
            board[posy][posx]=-1;
            n--;
        }
        
        for(int i=1;i<H+1;i++){
            for(int j=1;j<W+1;j++){
                if(board[i][j]!=-1)
                board[i][j] = -min(board[i-1][j-1],0) - min(board[i-1][j],0) - min(board[i-1][j+1],0) -
                min(board[i][j-1],0) - min(board[i][j+1],0) - min(board[i+1][j-1],0) - min(board[i+1][j],0) -
                min(board[i+1][j+1],0);
            }
        }
        
        board.pop_back();
        board.erase(board.begin());
        for(int i=0;i<H;i++){
            board[i].pop_back();
            board[i].erase(board[i].begin());
        }
        
        return board;
    }
};


int main()
{
  Solution res;
  vector<vector<int>> board = res.GenerateMap(8, 10, 16);
  for(int i=0;i<8;i++){
      for(int j=0;j<10;j++){
          if(board[i][j]!=-1) cout<<" ";
          cout<<board[i][j]<<"  ";
      }
      cout<<'\n';
  }
  return 0;
}
