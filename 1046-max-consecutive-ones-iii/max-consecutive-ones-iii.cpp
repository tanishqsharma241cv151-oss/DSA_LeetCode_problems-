class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //find longest subarray with atmost k 0's.
        int n=nums.size();
        int l=0,r=0;
        int len=0,maxlen=0;
        int zeroes=0;
        while(r<n){
            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }
            if(nums[r]==0)zeroes++;
            if(zeroes<=k){
                len=r-l+1;
                maxlen=max(len,maxlen);
            }
            r++;
        }
        return maxlen;
    }
};