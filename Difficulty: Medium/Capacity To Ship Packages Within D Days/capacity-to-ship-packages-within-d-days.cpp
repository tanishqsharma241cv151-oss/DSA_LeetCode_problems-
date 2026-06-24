class Solution {
  public:
    bool possible(vector<int>&arr,int D,int mid){
        int s=0,day=1;
        for(auto i:arr){
            if(s+i>mid){
                day++;
                s=i;
            }
            else{
                s+=i;
            }
        }
        return day<=D;
    }
    int leastWeightCapacity(vector<int>& arr, int D) {
        int sum=0, maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,D,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};