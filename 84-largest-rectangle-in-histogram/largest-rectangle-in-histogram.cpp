class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        long long area=1;
        long long maxi=LLONG_MIN;
        int el=1,nse=-1,pse=-1;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                el=st.top();st.pop();
                nse=i;pse=st.empty()?-1:st.top();
                maxi=max(maxi,heights[el]*1LL*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;el=st.top();st.pop();
            pse=st.empty()?-1:st.top();
            maxi=max(maxi,heights[el]*1LL*(nse-pse-1));
        }
        return maxi;

    }
};