class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int i=0,j=0,count=0;
        vector<int>hash(3,0);
        for(int j=0;j<n;j++){
            hash[s[j]-'a']++;
            while(hash[0]>0&&hash[1]>0&&hash[2]>0){//valid window.
                count+=n-j;
                hash[s[i]-'a']--;
                i++;
            }
        }
        return count;
    }
};