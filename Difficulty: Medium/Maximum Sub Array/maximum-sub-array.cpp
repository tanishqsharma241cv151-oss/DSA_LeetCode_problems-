class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n=arr.size();
        int maxstart=0,maxend=-1;
        int start=0,end=-1;
        int len=0,maxlen=-1;
        int sum=0,maxsum=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                if(sum==0){start=i;}
                sum+=arr[i];
                len++;
                
                if(sum>maxsum ||(sum==maxsum && len>maxlen)){
                    maxsum=sum;maxlen=len;maxstart=start;maxend=i;
                }
                
            }
            else{
                sum=0;len=0;
                if(arr[i]<0) continue;
            }
            
        }
        if (maxend==-1) return {-1};
        vector<int>ans(arr.begin()+maxstart,arr.begin()+maxend+1);
        return ans;
        
    }
};