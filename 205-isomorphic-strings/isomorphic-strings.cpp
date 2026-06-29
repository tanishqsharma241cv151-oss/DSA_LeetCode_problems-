class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m=s.size();
        int n=t.size();
        
        vector<int>arr1(256,-1);
        vector<int>arr2(256,-1);
        //to track the index of last occurence of a character
        //the goal is to ensure that the pattern of occurence and repetition of characters is the same in both strings.
        for(int i=0;i<n;i++){
            if(arr1[s[i]]!=arr2[t[i]]) return false;
            arr1[s[i]]=i;
            arr2[t[i]]=i;     
        }
        return true;

    }
};