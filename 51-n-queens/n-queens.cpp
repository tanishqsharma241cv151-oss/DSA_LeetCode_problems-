class Solution {
public:
    bool safe(int row,int col,vector<string>&board,int n){
        if(row<0||col<0||row>=n||col>=n) return false;
        int row1=row,col1=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;col--;
        }
        row=row1;col=col1;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        row=row1,col=col1;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;col--;
        }
        row=row1,col=col1;
        return true;
    }
    void fill(vector<vector<string>>&ans,vector<string>&board,int col,int n){
        if(col==n){
            ans.push_back(board);return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                fill(ans,board,col+1,n);
                board[row][col]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        int col=0;
        fill(ans,board,col,n);
        return ans;
    }
};