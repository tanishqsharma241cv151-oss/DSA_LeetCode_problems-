class Solution {
  public:
    string frequencySort(string &s) {
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
            ans.append(it.first,it.second);
        }
        return ans;
        
    }
};