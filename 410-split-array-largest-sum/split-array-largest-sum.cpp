class Solution {
public:
    bool possible(vector<int>&nums,int k,int mid){
        int subarray=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                subarray++;
                sum=nums[i];
                if(subarray>k)return false;    
            }
            else{
                sum+=nums[i];
            }
        }
        return subarray<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int low=maxi,high=sum;
        if(nums.size()<k) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};