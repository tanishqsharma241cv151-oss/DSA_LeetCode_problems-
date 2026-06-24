class Solution {
public:
    bool possible(vector<int>&weights,int days,int mid){
        int s=0, d=1;
        for(auto w:weights){
            if(s+w>mid){
                d++;
                s=w;
            }
            else{
                s+=w;
            }   
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(weights,days,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};