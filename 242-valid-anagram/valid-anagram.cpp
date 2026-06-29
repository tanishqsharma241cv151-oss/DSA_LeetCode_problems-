class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m) return false;
        vector<int>m1(256,0);
        vector<int>m2(256,0);
        for(int i=0;i<n;i++){
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(int i=0;i<m1.size();i++){
            if(m1[i]!=m2[i]) return false;
        }
        return true;
    }
};