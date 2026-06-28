class Solution {
  public:
    int countbefore(vector<vector<int>>&mat,int mid){
        int m=mat.size(),n=mat[0].size(),count=0;
        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]<=mid){
                    count+=j+1;
                    break;
                }
            }
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        int m=mat.size(),n=mat[0].size();
        int mini=INT_MAX, maxi=INT_MIN;
        for(int i=0;i<m;i++){
            mini=min(mini,mat[i][0]);
            maxi=max(maxi,mat[i][n-1]);
        }
        int low=mini,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(countbefore(mat,mid)>(m*n)/2) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
