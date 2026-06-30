class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string ans="";
        unordered_map<char,int>hashmap;
        for(auto it:s) hashmap[it]++;
        vector<pair<int,char>>v;
        for(auto it:hashmap){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        for(auto it:v){
            for(int i=0;i<it.first;i++){
                ans+=it.second;
            }    
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};