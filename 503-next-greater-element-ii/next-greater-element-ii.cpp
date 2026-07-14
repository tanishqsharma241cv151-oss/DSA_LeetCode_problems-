class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //given array is circular so we ll use the concept of hypothetical index.
        int n=nums.size();
        stack<int>st;
        vector<int>ans;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()&&nums[i%n]>=st.top()){st.pop();} //warm up pass from i=2n-1 to i=n;
            if(i<n){ // real pass from i=n-1 to i=0;
                ans.push_back(st.empty()?-1:st.top()); 
            }
            st.push(nums[i%n]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};