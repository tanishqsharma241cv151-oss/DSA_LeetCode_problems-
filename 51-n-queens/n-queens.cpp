class Solution {
public:
    void fill(vector<vector<string>>&ans,vector<string>&board,int col,int n,vector<int>&lowerdia,vector<int>&upperdia,vector<int>&left){
        if(col==n){
            ans.push_back(board);return;
        }
        for(int row=0;row<n;row++){
            if(lowerdia[row+col]==0&&upperdia[(n-1)+col-row]==0&&left[row]==0){
                board[row][col]='Q';
                lowerdia[row+col]=1;
                upperdia[(n-1)+col-row]=1;
                left[row]=1;
                fill(ans,board,col+1,n,lowerdia,upperdia,left);
                board[row][col]='.';
                lowerdia[row+col]=0;
                upperdia[(n-1)+col-row]=0;
                left[row]=0;
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
        vector<int>lowerdia(2*n-1,0);
        vector<int>upperdia(2*n-1,0);
        vector<int>left(n,0);
        int col=0;
        fill(ans,board,col,n,lowerdia,upperdia,left);
        return ans;
    }
};