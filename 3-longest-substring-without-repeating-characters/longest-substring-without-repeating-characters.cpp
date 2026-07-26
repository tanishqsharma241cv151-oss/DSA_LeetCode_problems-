class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int left=0,right=0;
        int maxlen=0;
        string s1="";
        for(right=0;right<n;right++){
            char c=s[right];
            if(mpp.find(c)!=mpp.end()){
                //if its in the window, we move left.
                if(mpp[c]>=left){
                    left=mpp[c]+1;
                }
            }
            maxlen=max(maxlen,right-left+1);
            mpp[c]=right;
        }
        return maxlen;
    }
};