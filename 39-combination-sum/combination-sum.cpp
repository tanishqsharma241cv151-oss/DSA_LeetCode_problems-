class Solution {
public:
    void solve(vector<int>&candidates,vector<int>&curr,vector<vector<int>>&ans,int i,int target){
        if(i==candidates.size()){
            if(target==0)ans.push_back(curr);
            return;
        }
        if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            solve(candidates,curr,ans,i,target-candidates[i]);
            curr.pop_back();
        }
        
        solve(candidates,curr,ans,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        int i=0;
        solve(candidates,curr,ans,i,target);
        return ans;
    }
};