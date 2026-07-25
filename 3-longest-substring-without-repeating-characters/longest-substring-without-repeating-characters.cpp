class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int left=0,right=0;
        string s1="";
        while(left<n && right<n){
            if(mpp.find(s[right])==mpp.end()){
            }
            else{
                if(s1.size()<right-left){
                    s1=s.substr(left,right-left);
                }
                mpp.clear();
                left++;
                right=left;
            }
            mpp[s[right]]=1;
            right++;
        }
        if(right-left>s1.size()){
            s1=s.substr(left,right-left);
        }
        int m=s1.size();
        return m;
        
    }
};