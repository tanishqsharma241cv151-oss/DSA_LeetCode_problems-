class Solution {
  public:
    bool divisionsum(vector<int>&arr,int k,int mid){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=(arr[i]+mid-1)/mid; //equivalent to ceil((double)arr[i]/mid).
        }
        return sum<=k; //return true if sum<=threshold.
    }
    int smallestDivisor(vector<int>& arr, int k) {
        int low=1,high=*max_element(arr.begin(),arr.end());
        if(k<arr.size()){return -1;}
        while(low<=high){
            int mid=low+(high-low)/2;
            if(divisionsum(arr,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    
    }
};
