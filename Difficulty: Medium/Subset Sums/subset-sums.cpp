class Solution {
  public:
    void solve(vector<int>&arr,vector<int>&ans,int i,int sum){
        if(i==arr.size()){
            ans.push_back(sum);
            return;
        }
        solve(arr,ans,i+1,sum);
        sum+=arr[i];
        solve(arr,ans,i+1,sum);
        sum-=arr[i];
    }
    vector<int> subsetSums(vector<int>& arr) {
        vector<int>ans;
        int i=0,sum=0;
        solve(arr,ans,i,sum);
        return ans;
    }
};