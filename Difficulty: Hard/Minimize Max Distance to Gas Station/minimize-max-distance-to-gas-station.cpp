class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        int n=stations.size();
        if(n<=1){return 0;}
        vector<int>howmany(n-1,0);
        //store the initial difference between given stations,and the section index in priority queue.
        priority_queue<pair<long double,int>>pq;
        for(int i=0;i<n-1;i++){ //arr will have n-1 sections.
            pq.push({stations[i+1]-stations[i],i});
        }
        //now start adding stations in sections one by one;
        for(int gas=1;gas<=K;gas++){
            auto tp=pq.top(); pq.pop();
            int secind=tp.second;
            howmany[secind]++;
            long double inidiff=stations[secind+1]-stations[secind];
            long double newseclen=inidiff/(long double)(howmany[secind]+1);
            pq.push({newseclen,secind});
        }
        return pq.top().first;
    }
};