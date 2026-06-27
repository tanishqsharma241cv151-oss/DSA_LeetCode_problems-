class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(mat[i][j],mat[j][i]); //transpose done;
            }
        }
        for(int i=0;i<n/2;i++){             // sw      
            swap(mat[i],mat[n-(i+1)]);
        }
        
    }
};
