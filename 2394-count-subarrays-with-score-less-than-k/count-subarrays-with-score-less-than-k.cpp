class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n=nums.size();
        long long l=0,r=0,score=0,len=0,sum=0,count=0;
        while(r<n){
            sum+=nums[r];len++;score=sum*len;
            while(score>=k && l<=r){
                //reduce the window size.
                sum-=nums[l];l++;len--;
                score=sum*len;
            }
            if(score<k){
                count+=r-l+1;r++;
            }
        }
        return count;
    }
};