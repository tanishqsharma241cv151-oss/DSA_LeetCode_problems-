class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n=arr.size(),m=arr[0].size();
        int maxcount=0,ind=-1;
        for(int i=0;i<n;i++){
            int count=0;
            int low=0,high=m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(arr[i][mid]==0)low=mid+1;
                else high=mid-1;
            }
            count+=m-low;
            if(maxcount<count){
                maxcount=count,ind=i;
            }
        }
        return ind;
    }
};