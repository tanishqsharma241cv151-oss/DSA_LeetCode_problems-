class Solution {
public:
    bool find(vector<vector<char>>& board,string&word,int i,int j,int ind){
        if(ind==word.size()) return true; //true if we have found all the letters in the matrix board.
        int m=board.size(),n=board[0].size();
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='$'||board[i][j]!=word[ind]) return false;
        char temp=board[i][j];
        board[i][j]='$'; //its been marked visited.
        //iterate through all 4 directions.
        bool found = find(board, word, i + 1, j, ind + 1) ||
                    find(board, word, i - 1, j, ind + 1) ||
                    find(board, word, i, j + 1, ind + 1) ||
                    find(board, word, i, j - 1, ind + 1); 
        
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ind=0;
        vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[ind] && find(board,word,i,j,ind)){
                    return true;
                }
            }
        }
        return false;
    }
};