class Solution {
public:
    bool bouquets(vector<int>bloomDay,int k,int m,int mid){
        int bouquet=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                bouquet+=count/k;
                count=0;
            }        
        }
        bouquet+=count/k;
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=INT_MIN,mini=INT_MAX;
        for(auto it:bloomDay){
            mini=min(mini,it);
            maxi=max(maxi,it);
        }
        int low=mini,high=maxi;
        if(bloomDay.size()< (long long)m*k) return -1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bouquets(bloomDay,k,m,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};