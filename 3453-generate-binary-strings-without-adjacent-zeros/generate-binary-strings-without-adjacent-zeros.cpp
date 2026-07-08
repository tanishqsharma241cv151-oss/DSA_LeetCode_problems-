class Solution {
public:
    void solve(string&s,vector<string>&ans,int n){
        if(s.size()==n){ans.push_back(s); return;}
        if(s.empty()){
            s+='0';
            solve(s,ans,n);
            s.pop_back();
            s+='1';
            solve(s,ans,n);
            s.pop_back();
        }
        else{
            if(s.back()=='0'){
                s.append("1");
                solve(s,ans,n);
                s.pop_back();
            }
            else{
                s.append("0");
                solve(s,ans,n);
                s.pop_back();
                s.append("1");
                solve(s,ans,n);
                s.pop_back();
            }
        }

    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string s="";
        solve(s,ans,n);
        return ans;
    }
};