class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(); //n x m matrix.
        int maxcount=-1,ind=-1;
        for(int i=0;i<n;i++){
            sort(mat[i].begin(),mat[i].end());
            int low=0,high=m-1;
            int count=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(mat[i][mid]==0) low=mid+1;
                else high=mid-1;
            }
            count+=m-low;
            if(count>maxcount){
                maxcount=count;ind=i;
            }
        }
        return {ind,maxcount};
    }
};