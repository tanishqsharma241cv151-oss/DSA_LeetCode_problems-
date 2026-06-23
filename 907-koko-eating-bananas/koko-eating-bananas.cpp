class Solution {
public:
    long long reqtime(vector<int>&piles,int mid){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time+=((long long)piles[i]+mid-1)/mid;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=*max_element(piles.begin(),piles.end());
        int low=1,high=m;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(reqtime(piles,mid)<=h){ //decrease eating speed.
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1; //increase eating speed.
            }    
        }
        return ans;
    }
};