class Solution {
public:
    bool ispossible(vector<vector<char>>&board,int i,int j,char num){
        for(int k=0;k<9;k++){ 
            if(board[i][k]==num)return false;
            if(board[k][j]==num)return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==num)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){continue;}
                else{
                    for(char num='1';num<='9';num++){
                        if(ispossible(board,i,j,num)){
                            board[i][j]=num;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j]='.';
                        }
                    }
                    return false; //none of the ch from 1 to 9 could be put in the blank space
                }
            }
        }
        return true; //the board was completely full so the for loops didnt run.
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};