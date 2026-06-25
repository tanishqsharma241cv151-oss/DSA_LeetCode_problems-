class Solution {
  public:
    bool possible(vector<int>&arr,int k,int mid){
        int painter=1,sum=0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                painter++;
                sum=arr[i];
                if(painter>k){return false;}
            }
            else{
                sum+=arr[i];
            }
        }
        return painter<=k;
    }
    int minTime(vector<int>& arr, int k) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
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