class Solution {
public:
    int expand(string s, int left, int right){
        int n=s.size();
        while(left>=0 && right<=n-1 && s[left]==s[right]){
            left--,right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=1;
        int start=0;
        for(int i=0;i<n-1;i++){
            int len1=0,len2=0;
            if(s[i]==s[i+1]){
                len1=expand(s,i,i+1);}
            if(i>0 && s[i+1]==s[i-1]){
                len2=expand(s,i-1,i+1);
            }
            if(len1>maxlen){
                maxlen=len1;
                start=i-(len1-1)/2;
            }
            if(len2>maxlen){
                maxlen=len2;
                start=i-(len2-1)/2;
            }      
        }
        return s.substr(start,maxlen);  
    }
};