class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //do a bs over the columns.
        int m=mat.size(),n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
        //take the max element in the mid col so it satisfies the criteria of element>top, element>bottom counterpart.
            int maxi=INT_MIN,row=-1;
            for(int i=0;i<m;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];row=i;
                }
            }
        //max element in the col can potentially be a peak, to confirm we check if maxi>right,maxi>left counterpart.
            int left=(mid==0)?-1:mat[row][mid-1];
            int right=(mid==n-1)?-1:mat[row][mid+1];
            if(mat[row][mid]>left && mat[row][mid]>right) return {row,mid};
            else if(mat[row][mid]<=left) high=mid-1;
            else if(mat[row][mid]<=right) low=mid+1;
        }
        return {-1,-1}; //dummy statement.

    }
};