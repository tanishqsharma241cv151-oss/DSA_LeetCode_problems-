class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int>st;
        int n=arr.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            ans.push_back(st.empty()?-1:st.top());
            st.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};