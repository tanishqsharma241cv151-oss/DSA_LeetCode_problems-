class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size(); //m-rows,n-columns.
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxi=INT_MIN,row=-1; //row is the index of the row in which maximum element in col mid exists.
            for(int i=0;i<m;i++){
                if(maxi<mat[i][mid]){
                    maxi=mat[i][mid];row=i; 
                }
            }
            int left=(mid==0)?INT_MIN:mat[row][mid-1];
            int right=(mid==n-1)?INT_MIN:mat[row][mid+1];
            if(mat[row][mid]>=left&&mat[row][mid]>=right) return {row,mid};
            else if(mat[row][mid]<left) high=mid-1;
            else if(mat[row][mid]<right) low=mid+1;
            
        }
        return {-1,-1};
    }
};
