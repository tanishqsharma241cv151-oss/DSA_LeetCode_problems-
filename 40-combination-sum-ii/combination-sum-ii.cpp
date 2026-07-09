class Solution {
public:
    void solve(vector<int>&arr,vector<vector<int>>&ans,vector<int>&curr,int i,int target){
        if(target==0){ans.push_back(curr);return;}

        for(int j=i;j<arr.size();j++){
            if(j>i && arr[j]==arr[j-1])continue;
            if(arr[j]>target)break;
            curr.push_back(arr[j]);
            solve(arr,ans,curr,j+1,target-arr[j]);
            curr.pop_back();
        }     
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i=0;
        vector<vector<int>>ans;
        vector<int>curr;
        vector<int>arr(candidates);
        sort(arr.begin(),arr.end());
        solve(arr,ans,curr,i,target);
        return ans;
    }
};