class Solution {
  public:
    string reverseWords(string &s) {
        int n=s.size();
        int i=n-1;
        string ans="";
        while(i>=0){
            if(s[i]=='.'){
                i--;
                continue;
            }
            if(i<0) break;
            int end=i;
            while(i>=0 && s[i]!='.'){
                i--;
            }
            if(!ans.empty()) ans+='.';
            ans+=s.substr(i+1,end-i);
            
            
        }
        return ans;
    }
};