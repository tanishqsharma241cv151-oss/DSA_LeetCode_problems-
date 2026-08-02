class Solution {
public:
    long long appealSum(string s) {
        long long r=0,prev=0,sum=0,n=s.size();
        vector<int>hash(26,-1);
        while(r<n){
            if(hash[s[r]-'a']==-1){
                //its the first occurence for this character.
                sum+=(r+1)*(n-r);
            }
            else{
                //if its not the first occurence, the repeating chars are just the first occurrence for a smaller set of starting points.
                sum+=(r-hash[s[r]-'a'])*(n-r);
            }
            hash[s[r]-'a']=r; //recording the most recent occurence.
            r++;

        }
        return sum;
    }
};