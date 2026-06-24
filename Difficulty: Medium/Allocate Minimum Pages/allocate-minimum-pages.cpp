class Solution {
  public:
    int possible(vector<int>&arr,int k,int mid){
        int sum=0, count=1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>mid){
                sum=arr[i];
                count++;
                if(count>k){
                    return false;
                }
            }
            else{
                sum+=arr[i];
            }
        }
        return count<=k;
        
    }
    int findPages(vector<int> &arr, int k) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            sum+=arr[i];
        }
        int low=maxi,high=sum;
        if(arr.size()<k){return -1;}
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