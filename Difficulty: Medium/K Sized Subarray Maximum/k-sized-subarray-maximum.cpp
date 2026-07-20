class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        deque<int>dq;
        vector<int>ans;
        int start=0;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }
            while(!dq.empty()&&arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};