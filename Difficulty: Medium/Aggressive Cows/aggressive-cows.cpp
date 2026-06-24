class Solution {
  public:
    bool possible(vector<int>&stalls,int k,int mid){
        int count=1;int last=0;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-stalls[last]>=mid){
                count++;
                last=i;
            }
            if(count==k) break;
        }
        return count>=k;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int low=1,high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(stalls,k,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};