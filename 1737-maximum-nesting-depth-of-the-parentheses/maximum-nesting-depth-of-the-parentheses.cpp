class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int count=0, ans=0;
        for(auto it:s){
            if(it=='('){
                count++;
                ans=max(ans,count);
            }
            else if(it==')'){
                count--;
            }
        }   
        return ans;
    }
};