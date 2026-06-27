class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(); //ladder approach, keep pointer at the last element of the first row and move down or left only.
        int i=0,j=n-1;
        while(i<m &&j>=0){
            if(matrix[i][j]<target) i++;
            else if(matrix[i][j]>target) j--;
            else return true;
        }
        return false;
    }
};