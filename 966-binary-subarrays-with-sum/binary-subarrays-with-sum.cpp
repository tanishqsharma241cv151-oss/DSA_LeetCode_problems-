class Solution {
public:
    int numofsubarrays(vector<int>&nums,int goal){
        //this function counts the number of subarrays with sum<=goal.
        int n=nums.size();
        int l=0,r=0,count=0,sum=0;
        if(goal<0)return 0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                //trim the window.
                sum-=nums[l];
                l++;
            }
            if(sum<=goal){
                count+=r-l+1;
                r++;
            }
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=numofsubarrays(nums,goal);
        int b=numofsubarrays(nums,goal-1);
        return a-b;
    }
};