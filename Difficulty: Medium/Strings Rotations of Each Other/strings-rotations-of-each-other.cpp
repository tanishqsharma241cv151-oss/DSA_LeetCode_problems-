class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        string s=s1+s1;
        if(s.find(s2)!=string::npos){ //found
            return true;
        }
        else return false;
    }
};