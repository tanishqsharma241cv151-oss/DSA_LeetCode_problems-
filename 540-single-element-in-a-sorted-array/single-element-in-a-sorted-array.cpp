class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=1,high=n-2;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid]) return nums[mid];
            else{
                if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
                    //we are on the left part and the element is on the right.
                    low=mid+1;
                }
                else{
                    //we are on the right part and element is on the left.
                    high=mid-1;
                }
            }
        }
        return -1; //dummy statement because we are using a non void function so we need to return something.
    }
};