class Solution {
public:
    int atmostk(vector<int>&nums,int k){
        int n=nums.size();
        int l=0,r=0,count=0,countodd=0;
        while(r<n){
            if(nums[r]%2==1){
                countodd++;
            }
            while(countodd>k){
                if(nums[l]%2==1){
                    countodd--;
                }
                l++;
            }
            if(countodd<=k){
                count+=r-l+1;r++;
            }
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int a=atmostk(nums,k);
        int b=atmostk(nums,k-1);
        return a-b;
    }
};