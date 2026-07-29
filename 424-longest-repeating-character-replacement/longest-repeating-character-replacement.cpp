class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int r=0,l=0;
        int maxlen=0;
        int maxfreq=0;
        vector<int>hash(26,0);
        while(r<n){
            hash[s[r]-'A']++; //we dont need the most frequent character, we need the count of the most frequent character in the window.
            maxfreq=max(maxfreq,hash[s[r]-'A']);
            if((r-l+1)-maxfreq>k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        } 
        return maxlen;
    }
};