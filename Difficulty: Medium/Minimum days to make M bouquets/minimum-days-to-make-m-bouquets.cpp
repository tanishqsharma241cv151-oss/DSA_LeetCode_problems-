class Solution {
  public:
    bool possible(vector<int>&arr,int k,int m,int&mid){
        int count=0,bouquet=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=mid){
                count++;
            }
            else{
                bouquet+=count/k;
                count=0;
            }
        }
        bouquet+=count/k;
        return bouquet>=m;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
        }
        int low=mini,high=maxi;
        if(arr.size()<(long long)m*k)return -1; //in case m bouquets never happen
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,k,m,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};