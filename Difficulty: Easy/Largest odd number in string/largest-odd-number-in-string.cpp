class Solution {
  public:
    string maxOdd(string s) {
        int n=s.size();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]%2==1){
                ans+=s.substr(0,i+1);
                break;
            }
        }
        return ans;
        
    }
};