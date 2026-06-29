class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        int n=s1.size(),m=s2.size();
        if(n!=m) return false;
        vector<int>hasharr(26,0);
        for(int i=0;i<n;i++){
            hasharr[s1[i]-'a']++;
            hasharr[s2[i]-'a']--;
        }
        for(int i=0;i<hasharr.size();i++){
            if(hasharr[i]!=0) return false;
        }
        return true;
    }
};