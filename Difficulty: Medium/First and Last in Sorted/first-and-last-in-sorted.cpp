class Solution {
  public:
    int lowerbound(vector<int>&arr,int x){
        int n=arr.size();
        int ans=n;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>&arr,int x){
        int n=arr.size();
        int ans=n;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> find(vector<int>& arr, int x) {//use lower bound and upper bound concept
        int n=arr.size();
        int lb=lowerbound(arr,x);
        int ub=upperbound(arr,x);
        if(lb==n || arr[lb]!=x){
            return {-1,-1};
        }
        else{
            return {lb,ub-1};
        }
        
    }
};