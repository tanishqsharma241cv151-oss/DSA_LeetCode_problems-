class Solution {
  public:
    void insert(stack<int>&st,int temp){
        if(st.empty()){
            st.push(temp);
        }
        else{
            int next=st.top();
            st.pop();
            insert(st,temp);
            st.push(next);
        }
    }
    void reverseStack(stack<int> &st) {
        if(!st.empty()){
            int temp=st.top();
            st.pop();
            reverseStack(st);
            insert(st,temp);
        }
    }
};