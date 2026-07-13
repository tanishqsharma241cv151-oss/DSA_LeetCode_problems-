class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char it:s){
            if(it=='(' || it=='{' || it=='['){st.push(it);}
            else if(st.empty()){
                return false;
            }
            else if((it==')' && st.top()=='(') || (it=='}' && st.top()=='{') || (it==']' && st.top()=='[')){
                st.pop();
            }
            else if((it==')' && st.top()!='(') || (it=='}' && st.top()!='{') || (it==']' && st.top()!='[')){
                return false;
            }
        }
        if(st.empty()) return true;
        else return false;  
    }
};