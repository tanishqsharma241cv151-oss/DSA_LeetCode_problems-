class Solution {
public:
    bool ispalindrome(string part){
        int left=0,right=part.size()-1;
        while(left<right){
            if(part[left]!=part[right]){
                return false;
            }
            left++;right--;
        }
        return true;
    }
    void parts(vector<vector<string>>&ans,vector<string>&res,string s){
        if(s.empty()){
            ans.push_back(res);
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(ispalindrome(part)){
                res.push_back(part);
                parts(ans,res,s.substr(i+1));
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        parts(ans,res,s);
        return ans;
    }
};