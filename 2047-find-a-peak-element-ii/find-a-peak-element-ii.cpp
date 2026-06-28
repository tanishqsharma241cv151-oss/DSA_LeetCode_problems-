class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            //take the max element in the mid column, as it could be the possible peak.
            int maxi=INT_MIN, row=-1;
            for(int i=0;i<m;i++){
                if(maxi<mat[i][mid]){
                    maxi=mat[i][mid]; row=i;
                }
            }
            //check maxi for the 4 peak conditions, maxi > its top,bottom,left and right counterparts.
            //since its the max element in the mid column it will already satsify maxi > top and bottom counterparts.
            int right=(mid==n-1)?-1:mat[row][mid+1];
            int left=(mid==0)?-1:mat[row][mid-1];
            if(maxi>right&& maxi>left) return {row,mid};
            else if(mat[row][mid]<right) low=mid+1;
            else if(mat[row][mid]<left) high=mid-1;   
        }
        return {-1,-1};

    }
};