class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0,count=0;
        vector<int>hash(3,-1);
        while(r<n){
            hash[s[r]-'a']=r;
            if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
                //all substrings before this substring and including this valid substring will also be valid.
                int a=min({hash[0],hash[1],hash[2]});
                count+=a-l+1;
            }
            r++;
        }
        return count;
    }
};