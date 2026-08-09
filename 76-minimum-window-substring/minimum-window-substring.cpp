class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        int n=s.size();
        int l=0,r=0,sInd=-1,count=0,minlen=INT_MAX;
        unordered_map<char,int>mpp;
        //prestore elements of t in the map.
        for(int i=0;i<m;i++){
            mpp[t[i]]++;
        }
        while(r<n){
            if(mpp[s[r]]>0){
                count++;
            }
            mpp[s[r]]--;
            while(count==t.size()){//we have found a valid window.
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sInd=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return sInd==-1?"":s.substr(sInd,minlen);
    }
};