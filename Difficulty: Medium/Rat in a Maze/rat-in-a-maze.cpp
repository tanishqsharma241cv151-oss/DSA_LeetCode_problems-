class Solution {
  public:
  
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    void move(vector<vector<int>>&maze,vector<string>&ans,string s,int row,int col){
        if(row==maze.size()-1 && col==maze.size()-1){ans.push_back(s);return;}
        if(row<0||col<0||row>=maze.size()||col>=maze.size()||maze[row][col]=='$'||maze[row][col]!=1){
            return;
        }
        int el=maze[row][col];
        maze[row][col]='$';
        move(maze,ans,s+"D",row+1,col);
        move(maze,ans,s+"L",row,col-1);
        move(maze,ans,s+"R",row,col+1);
        move(maze,ans,s+"U",row-1,col);
        maze[row][col]=el;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>ans;
        string s="";
        int row=0,col=0;
        move(maze,ans,s,row,col);
        return ans;
        
    }
};