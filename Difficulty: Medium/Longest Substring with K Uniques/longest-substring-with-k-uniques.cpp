class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int r=0,l=0,maxlen=0;
        int n=s.size();
        unordered_map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k && l<n){
                mpp[s[l]]--;
                if(mpp[s[l]]==0)mpp.erase(s[l]);
                l++;
            }
            if(mpp.size()==k) maxlen=max(maxlen,r-l+1);
            r++;
        } 
        if(maxlen==0)return -1;
        return maxlen;
    }
};