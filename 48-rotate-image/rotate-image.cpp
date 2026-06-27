class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //its basically doing transpose of the matrix and then reversing each row.
        //during transpose all diagonal elements remain same, upper and lower trangle elements get interchanged.
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                swap(matrix[i][j],matrix[j][i]); //transpose done;
            }
            reverse(matrix[i].begin(),matrix[i].end());//reversing the rows to get the 90 degrees rotates array.
        }    
    }
};