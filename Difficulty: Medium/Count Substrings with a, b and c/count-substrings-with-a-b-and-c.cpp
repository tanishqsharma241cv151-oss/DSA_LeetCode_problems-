class Solution {
  public:
    int countSubstring(string &s) {
        int n=s.size(),count=0;
        vector<int>lastseen(3,-1);
        int i=0;
        while(i<n){
            lastseen[s[i]-'a']=i;//records the last occurrence of characrers in string s.
            if(lastseen[0]!=-1&&lastseen[1]!=-1&&lastseen[2]!=-1){//min window.
                count+=1+min({lastseen[0],lastseen[1],lastseen[2]});
            }
            i++;
        }
        return count;
        
    }
};