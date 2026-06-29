class Solution {
public:
    bool rotateString(string s, string goal) {
        string a=s+s;
        if(a.find(goal)!=string::npos) return true;
        else return false;

    }
};