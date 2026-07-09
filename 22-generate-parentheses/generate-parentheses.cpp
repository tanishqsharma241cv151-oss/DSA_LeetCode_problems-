class Solution {
public:
    void solve(string&s,vector<string>&ans,int open,int close,int n){
        if(s.size()==n*2){ //base case.
            ans.push_back(s);return;
        }
        if(s.empty() || (open==close && open<n && close<n)){
            s+='(';open++;
            solve(s,ans,open,close,n); s.pop_back();open--;
        }
        else{
            if(open>close && open<n && close<n ){
                s+='(';open++;
                solve(s,ans,open,close,n); s.pop_back(); open--;
                s+=')';close++;
                solve(s,ans,open,close,n); s.pop_back(); close--;
            }
            else if(open==n && close<n){
                s+=')';close++;
                solve(s,ans,open,close,n); s.pop_back();close--;
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        int open=0,close=0;
        vector<string>ans;
        solve(s,ans,open,close,n);
        return ans;
    }

};