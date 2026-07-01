class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int>st;
        int len=0,maxlen=0;
        for(auto it:arr){st.insert(it);}
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