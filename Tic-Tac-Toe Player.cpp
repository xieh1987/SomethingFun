#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
    private:
        int size_n;
        vector<vector<char>> board;
        vector<int> row_sum;
        vector<int> col_sum;
        int diag=0, adiag=0;
 
    /** Initialize your data structure here. */
    public:
        TicTacToe(int n) : size_n(n), board(n, vector<char>(n)), row_sum(n,0), col_sum(n, 0) {
            cout<<"Board Generated! Enjoy Your Play!!!"<<endl;
        }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
        int move(int row, int col, int player) {
            if(player==1){
                this->board[row][col] = 'X';
                this->PrintBoard();
                ++row_sum[row];
                ++col_sum[col];
                if(row_sum[row]==this->size_n||col_sum[col]==this->size_n) return 1;
                if(row==col){
                    ++(this->diag);
                    if(diag==this->size_n) return 1;
                }
                if(row+col==this->size_n-1){
                    ++(this->adiag);
                    if(adiag==this->size_n) return 1;
                }
            }
            
            if(player==2){
                this->board[row][col] = 'O';
                this->PrintBoard();
                --row_sum[row];
                --col_sum[col];
                if(row_sum[row]==-this->size_n||col_sum[col]==-this->size_n) return 2;
                if(row==col){
                    --(this->diag);
                    if(diag==-this->size_n) return 2;
                }
                if(row+col==this->size_n-1){
                    --(this->adiag);
                    if(adiag==-this->size_n) return 2;
                }
            }
            return 0;
        }
        
        void PrintBoard(){
            for(int i=0;i<this->size_n;++i){
                for(int j=0;j<this->size_n;++j){
                    cout<<'|';
                    if(this->board[i][j]=='X'||this->board[i][j]=='O')
                        cout<<this->board[i][j];
                    else
                        cout<<' ';
                }
                cout<<"|\n";
            }
        }
};
 
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
*/

int main()
{
    TicTacToe board(3);
    int win = 0;
    win = board.move(0, 0, 1);
    cout<<"Winner: "<<win<<endl;
    win = board.move(0, 2, 2);
    cout<<"Winner: "<<win<<endl;
    win = board.move(2, 2, 1);
    cout<<"Winner: "<<win<<endl;
    win = board.move(1, 1, 2);
    cout<<"Winner: "<<win<<endl;
    win = board.move(2, 0, 1);
    cout<<"Winner: "<<win<<endl;
    win = board.move(1, 0, 2);
    cout<<"Winner: "<<win<<endl;
    win = board.move(2, 1, 1);
    cout<<"Winner: "<<win<<endl;
    return 0;
}
