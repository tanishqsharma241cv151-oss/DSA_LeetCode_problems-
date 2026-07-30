class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==1 || k==0) return 0;
        int n=nums.size();
        long long prod=1;
        int l=0,r=0;
        long long count=0;
        while(r<n){
            prod=(long long)prod*nums[r];
            while(prod>=k){
                prod=(long long)prod/nums[l];l++;
            }
            if(prod<k){
                count=(int)count+r-l+1;r++;
            }
        }
        return count;
    }
};