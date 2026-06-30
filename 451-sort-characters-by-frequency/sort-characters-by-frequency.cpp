class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string ans="";
        unordered_map<char,int>hashmap;
        for(auto it:s) hashmap[it]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:hashmap){
            pq.push({it.second,it.first});//element with highest frequency is at the top.
        }
        int m=pq.size();
        for(int i=0;i<m;i++){
        
            ans.append(pq.top().first,pq.top().second);
            pq.pop(); //removes the topmost element.
        }
        return ans;
    }
};