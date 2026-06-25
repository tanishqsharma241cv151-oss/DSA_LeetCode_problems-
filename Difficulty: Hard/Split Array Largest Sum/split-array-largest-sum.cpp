class Solution {
  public:
    bool possible(vector<int>&arr,int k,int mid){
        int subarray=1,sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                subarray++;
                sum=arr[i];
                if(subarray>k)return false;
            }
            else{
                sum+=arr[i];
            }
        }
        return subarray<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        int low=maxi,high=sum;
        if(arr.size()<k)return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};