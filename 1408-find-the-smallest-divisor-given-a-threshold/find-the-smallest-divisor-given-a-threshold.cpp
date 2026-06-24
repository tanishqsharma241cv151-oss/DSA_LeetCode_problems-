class Solution {
public:
    bool divisionsum(vector<int>&nums,int threshold,int &mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=(nums[i]+mid-1)/mid; //this gives ceiling of nums[i]/mid.
        }
        return sum<=threshold;//return true if sum<=threshold.
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end()); //* accesses the element at the iterator.
        if(threshold<nums.size()){return -1;}
        while(low<=high){
            int mid=low+(high-low)/2;
            if(divisionsum(nums,threshold,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};