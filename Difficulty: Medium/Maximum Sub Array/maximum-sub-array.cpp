class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        int n=arr.size();
        int len=0,maxlen=0;
        int sum=0,maxsum=0;
        int start=-1,maxstart=0,maxend=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                if(sum==0) start=i;
                sum+=arr[i];
                len++;
                if(sum>maxsum || sum==maxsum && len>maxlen ){
                    maxstart=start;maxlen=len;maxsum=sum;maxend=i;
                }
            }
            else{
                sum=0;len=0;
                if(arr[i]<0)continue;
            }
        }
        if(start==-1) return{-1};
        vector<int>ans(arr.begin()+maxstart,arr.begin()+maxend+1);
        return ans;
        
        
    }
};