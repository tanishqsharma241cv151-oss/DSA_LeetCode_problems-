class Solution {
  public:
    bool safe(vector<vector<int>>&adj,vector<int>&color,int i,int node){
        for(int k=0;k<adj[node].size();k++){
            if(color[adj[node][k]]==i)return false;
        }
        return true;
    }
    bool solve(int v,vector<vector<int>>&adj,vector<int>&color,int m,int node){
        if(node==v) return true;
        for(int i=0;i<m;i++){
            if(safe(adj,color,i,node)){
                color[node]=i;
                if(solve(v,adj,color,m,node+1))return true;;
                color[node]=-1;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        int node=0;
        vector<int>color(v,-1);
        vector<vector<int>>adj(v);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(v,adj,color,m,node);
    }
};