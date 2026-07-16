class Solution {
public:
    vector<int>findpse(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;

    }
    vector<int>findnse(vector<int>&heights){
        int n=heights.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop(); 
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse=findnse(heights);
        vector<int>pse=findpse(heights);
        long long area=1;
        long long maxi=LLONG_MIN;
        for(int i=0;i<n;i++){
            area=heights[i]*1LL*(nse[i]-pse[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;

    }
};