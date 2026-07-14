class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1){return;}
        int p=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                p=i;break;}
        }
        if(p==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int q=0;
        for(int j=n-1;j>=0;j--){
            if(nums[j]>nums[p]){
                q=j;break;}
        }
        swap(nums[p],nums[q]);
        sort(nums.begin()+p+1,nums.end());

    }
};