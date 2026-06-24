class Solution {
public:
    int bouquets(vector<int>bloomDay,int k,int mid){
        int bouquet=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
                if(count==k){
                    bouquet++;
                    count=0;
                }
            }
            else{
                count=0;
            }        
        }
        return bouquet;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int low=mini,high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(bouquets(bloomDay,k,mid)<m){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};