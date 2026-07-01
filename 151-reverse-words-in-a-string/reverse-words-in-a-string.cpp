class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int i=n-1; 
        int start=-1;
        while(i>=0){
           while(i>=0 && s[i]==' '){i--;continue;}
           if(i<0) break;
           int end=i;
           while(i>=0 && isalnum(s[i])){
                start=i;
                i--;
           }
           if(!ans.empty()){ans.append(" ");}
           ans+=s.substr(start,end-start+1);  
        }
        return ans;
    }
};