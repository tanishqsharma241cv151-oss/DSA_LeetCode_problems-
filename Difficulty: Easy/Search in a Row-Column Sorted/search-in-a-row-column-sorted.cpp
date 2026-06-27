class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n=mat.size(),m=mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){ //beacuse i only increases while j only decreases.
            if(mat[i][j]<x) i++;
            else if(mat[i][j]>x) j--;
            else{
                return true;
            }
        }
        return false;
    }
};