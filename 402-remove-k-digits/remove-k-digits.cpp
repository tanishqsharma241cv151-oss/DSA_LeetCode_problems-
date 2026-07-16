class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>st;
        int initial=k;
        for(char ch:num){
            while(!st.empty()&&ch<st.top()&&k>0){
                st.pop();k--;
            }
            st.push(ch);
        }
        while(k>0){
            st.pop();k--;
            if(st.empty()) return "0";
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        if(ans.empty())return "0"; //executes if ans had all 0's initially which were popped earlier.
        return ans;
    } 
};