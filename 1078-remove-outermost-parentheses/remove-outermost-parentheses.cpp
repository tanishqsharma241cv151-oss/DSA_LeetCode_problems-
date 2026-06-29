class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0;
        for( char it:s){
            if(it=='('){
                count++;
                if(count>1) ans+='(';
            }
            if(it==')'){
                count--;
                if(count>0)ans+=')';
            }   
        }
        return ans;
    }
};