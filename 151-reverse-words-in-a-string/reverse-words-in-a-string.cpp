class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        int i=n-1; 
        while(i>=0){ //run a while loop from right to left on the input string s.
            if(s[i]==' '){
                i--;continue;
            }
            if(i<0) break;
            int end=i;
            while(i>=0 && s[i]!=' '){
                i--;     
            }
            //append the word into ans.
            //now add a space after every word, dont add a space if the ans substring is empty dont add space.
            if(!ans.empty()){
                ans+=' ';
            }
            ans+=s.substr(i+1,end-i);
        }
        return ans;
    }
};