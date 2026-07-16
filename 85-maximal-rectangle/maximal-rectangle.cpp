class Solution {
public:
    int maxarea(vector<int>&arr){
        int n=arr.size();//no. of cols.
        stack<int>st;
        int maxi=INT_MIN;
        int el=-1;
        int nse=-1,pse=-1;
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<arr[st.top()]){
                el=st.top();nse=i;st.pop();pse=st.empty()?-1:st.top();
                maxi=max(maxi,arr[el]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            el=st.top();nse=n;st.pop(),pse=st.empty()?-1:st.top();
            maxi=max(maxi,arr[el]*(nse-pse-1));
        }
        return maxi;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();//number of columns.
        int n=matrix.size(); // number of rows.
        int maxi=INT_MIN;
        vector<int>arr(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    arr[j]+=matrix[i][j]-'0';
                }
                else{
                    arr[j]=0;
                }  
            }
            maxi=max(maxi,maxarea(arr));
        }
        return maxi; 
    }
};