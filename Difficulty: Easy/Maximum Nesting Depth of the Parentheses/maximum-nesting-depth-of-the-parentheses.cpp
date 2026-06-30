class Solution {
  public:
    int maxDepth(string &s) {
        int count=0,maxcount=0;
        for(auto it:s){
            if(it=='('){
                count++;maxcount=max(maxcount,count);
            }
            else if(it==')'){
                count--;
            }
        }
        return maxcount;
    }
};