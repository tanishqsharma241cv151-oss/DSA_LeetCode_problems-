class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //we need to find maxlength subarray with atmost 2 types of numbers.
        int n=fruits.size();
        int r=0,l=0,maxlen=0;
        unordered_map<int,int>mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            if(mpp.size()<=2){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};