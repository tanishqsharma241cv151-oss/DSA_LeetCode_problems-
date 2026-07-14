class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            int maxi=INT_MIN;
            int j=i+1;
            while(j<n){
                maxi=max(maxi,arr[j]);
                j++;
            }
            arr[i]= i<n-1?maxi:-1;
        }
        return arr;
    }
};