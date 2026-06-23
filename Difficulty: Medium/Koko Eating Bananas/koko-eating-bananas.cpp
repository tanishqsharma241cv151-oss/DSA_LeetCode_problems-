class Solution {
  public:
    long long timereq(vector<int>&arr,int mid){
        long long time=0;
        for(int i=0;i<arr.size();i++){
            time+=((long long)arr[i]+mid-1)/mid; //this gives ceil of piles[i]/mid
        }
        return time;
    }
    int kokoEat(vector<int>& arr, int k) {
        int m=*max_element(arr.begin(),arr.end());
        int low=1,high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(timereq(arr,mid)<=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};