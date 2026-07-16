class Solution {
  public:
    vector<int>findnse(vector<int>&arr){
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[i]<=arr[st.top()]){st.pop();}
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findpse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<arr[st.top()]){st.pop();}
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubMins(vector<int> &arr) {
        int n=arr.size(),sum=0,mod=1e9+7;
        vector<int>nse=findnse(arr);
        vector<int>pse=findpse(arr);
        int left=-1,right=-1;
        for(int i=0;i<n;i++){
            left=i-pse[i];
            right=nse[i]-i;
            sum=(sum+(right*left*1LL*arr[i]%mod))%mod;
        }
        return sum;
    }
};