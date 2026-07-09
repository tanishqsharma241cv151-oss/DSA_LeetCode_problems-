class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&arr,int i){
        if(i==nums.size()){
            ans.push_back(arr);return;
        }
        solve(nums,ans,arr,i+1);
        arr.push_back(nums[i]);
        solve(nums,ans,arr,i+1);
        arr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<vector<int>>ans;
        vector<int>arr;
        solve(nums,ans,arr,i);
        return ans;
    }
};