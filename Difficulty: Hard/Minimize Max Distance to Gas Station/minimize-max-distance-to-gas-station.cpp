class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n=stations.size();
        if(n<=1)return 0;
        priority_queue<pair<long double,int>>pq;
        vector<int>howmany(n-1,0);
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int gasstations=1;gasstations<=K;gasstations++){
            auto tp=pq.top();pq.pop();
            int secind=tp.second;
            howmany[secind]++;
            long double inidiff=stations[secind+1]-stations[secind];
            long double newseclen=inidiff/(long double)(howmany[secind]+1);
            pq.push({newseclen,secind});
        }
        return pq.top().first;
        
    }
};