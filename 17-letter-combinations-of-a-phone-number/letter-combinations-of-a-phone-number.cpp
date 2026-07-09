class Solution {
public:
    void solve(map<int,vector<char>>&mpp,vector<string>&ans,string&digits,string&curr,int ind){
        if(ind==digits.size()){
            ans.push_back(curr);return;}
        for(int i=0;i<mpp[digits[ind]-'0'].size();i++){
            curr+=mpp[digits[ind]-'0'][i];
            solve(mpp,ans,digits,curr,ind+1);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        map<int,vector<char>>mpp={
            {2,{'a','b','c'}},{3,{'d','e','f'}},{4,{'g','h','i'}},{5,{'j','k','l'}},{6,{'m','n','o'}},{7,{'p','q','r','s'}},{8,{'t','u','v'}},{9,{'w','x','y','z'}}
        };
        vector<string>ans;
        string curr="";
        int ind=0;
        solve(mpp,ans,digits,curr,ind);
        return ans;
    }
};