class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi1=INT_MIN,maxi2=INT_MIN,n=nums.size();
        int mul1=1,mul2=1;
        for(int i=0;i<n;i++){
            mul1*=nums[i];
            mul2*=nums[n-1-i];
            maxi1=max(maxi1,mul1);
            maxi2=max(maxi2,mul2); 
            if(mul1==0){
                mul1=1;
            }
            if(mul2==0){
                mul2=1;
            }
        }

    return max(maxi1,maxi2);
    }
};