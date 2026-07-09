class Solution {
public:
    long long power(int x,int k){
        if(k==0)return 1;
        long long mod=1e9+7;
        long long ans=1;
        while(k>0){
            if(k%2==0){
                x=(1LL*x*x)%mod;
                k=k/2;
            }
            else if(k%2==1){
                ans=(ans*x)%mod;
                k--;
            }
        }
        return ans%mod;
        
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long mod=1e9+7;
        int n=nums.size();
        int left=0,right=n-1;
        long long count=0;
        while(left<=right){
            int k=0;
            if(nums[left]+nums[right]>target){
                right--;
            }
            else if(nums[left]+nums[right]<=target){
                k=right-left;
                count=(count+power(2,k))%mod;
                left++;
            }  
        }
        return count;
        
    }
};