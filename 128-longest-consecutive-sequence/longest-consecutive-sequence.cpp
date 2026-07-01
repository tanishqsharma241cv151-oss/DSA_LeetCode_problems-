class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int len=0,maxlen=0;
        for(auto it:nums){st.insert(it);}
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int x=it;
                while(st.find(x)!=st.end()){
                    len++;
                    x++;
                }
                maxlen=max(maxlen,len);
                len=0;
            }
            
        }
        return maxlen;
    }
};