class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target){low=mid+1;}
            else high=mid-1;   
        }    
        int l=0,h=m-1;
        if(high<0) high=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(matrix[high][mid]<=target){
                l=mid+1;
            }
            else h=mid-1;
        }
        if(h<0) h=0;
        return matrix[high][h]==target;   
    }
};