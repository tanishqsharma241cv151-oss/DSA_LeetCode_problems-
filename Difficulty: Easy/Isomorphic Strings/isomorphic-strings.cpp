class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        int n=s2.size();
        vector<int>m1(256,-1);
        vector<int>m2(256,-1);
        for(int i=0;i<=n-1;i++){
            if(m1[s1[i]]!=m2[s2[i]]) return false;
            m1[s1[i]]=i;
            m2[s2[i]]=i;
        }
        return true;
    }
};