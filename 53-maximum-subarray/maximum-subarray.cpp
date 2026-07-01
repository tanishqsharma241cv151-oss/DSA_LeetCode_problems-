class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0,maxsum=INT_MIN;
        int start=-1,end=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;}
        
        }
        return maxsum;
    }
};