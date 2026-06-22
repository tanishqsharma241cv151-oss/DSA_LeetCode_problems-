class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int ans=INT_MAX, n=arr.size();
        int low=0,high=n-1;
        int i=n+1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]<arr[high]){
                ans=min(ans,arr[low]);
                if(ans==arr[low]){
                    i=low;
                }
                break;
            }
            if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                if(ans==arr[low]){
                    i=low;
                }
                low=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                if(ans==arr[mid]){
                    i=mid;
                }
                high=mid-1;
            }
        }
        return i;
        
    }
};
