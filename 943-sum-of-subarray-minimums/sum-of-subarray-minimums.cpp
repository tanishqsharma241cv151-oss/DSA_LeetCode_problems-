class Solution {
public:
    vector<int> findnse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            //lets find the index of the next smaller element for arr[i];
            while(!st.empty()&&arr[i]<=arr[st.top()]){
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        int right=-1,left=-1;
        int sum=0,mod=(int)1e9+7;
        vector<int>nse=findnse(arr);
        vector<int>pse=findpse(arr);
        for(int i=0;i<n;i++){
            right=nse[i]-i;
            left=i-pse[i];
            sum=(sum+(right*left*1LL*arr[i]%mod))%mod;
        }
        return sum;
    }
};