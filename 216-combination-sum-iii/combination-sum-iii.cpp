class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&curr,int ind,int k,int n){
        if(n==0 && curr.size()==k){
            ans.push_back(curr);return;
        }
        if(n<0 || curr.size()>k) return;
        for(int i=ind;i<nums.size();i++){
            if(nums[i]>n)break;
            curr.push_back(nums[i]);
            solve(ans,nums,curr,i+1,k,n-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int ind=0;
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>curr;
        solve(ans,nums,curr,ind,k,n);
        return ans;
    }
};