class Solution {
  public:
    void insert(stack<int>&st,int temp){
        if(st.empty()){
            st.push(temp);
        }
        else{
            if(st.top()>temp){
                int greater=st.top();
                st.pop();
                insert(st,temp);
                st.push(greater);
            }
            
            else{
                st.push(temp);
            }
            
        }
        
        
    }
    void sortStack(stack<int> &st) {
        if(!st.empty()){
            int temp=st.top();
            st.pop();
            sortStack(st);
            insert(st,temp);
        }
    }
};
