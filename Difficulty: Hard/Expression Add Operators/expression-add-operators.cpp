class Solution {
  public:
    
    void solve(vector<string>&ans, string s, const string&currexp, long currval,
        int target, int ind, long residual){
        if(ind==s.size()){
            if(currval==target) ans.push_back(currexp);
            return;
        }
        string temp="";
        long val=0;
        for(int i=ind;i<s.size();i++){
            if(i>ind && s[ind]=='0') break;  // note: fixed index + break, not return
            temp+=s[i];
            val=val*10+(s[i]-'0');
            if(ind==0){
                solve(ans,s,currexp+temp,val,target,i+1,val);
            }
            else{
                solve(ans,s,currexp+"+"+temp,currval+val,target,i+1,val);
                solve(ans,s,currexp+"-"+temp,currval-val,target,i+1,-val);
                if(val!=0 && llabs(residual)>LONG_MAX/llabs(val)) continue;
                solve(ans,s,currexp+"*"+temp,currval-residual+val*residual,target,i+1,val*residual);
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        vector<string> ans;
        string currexp;
        solve(ans,s,currexp,0,target,0,0);
        return ans;
    
        
    }
};