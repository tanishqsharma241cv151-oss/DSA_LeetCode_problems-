class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int j=0,count=0;
        vector<int>hash(26,0);
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            while(hash[s[i]-'a']==k){
                count+=n-i;
                hash[s[j]-'a']--;
                j++;
            }
        }
        return count;
    }
};