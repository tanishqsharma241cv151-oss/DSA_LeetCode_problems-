class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int count=0,ans=-1;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        for(int i=0;i<n;i++){
            if(n){
                pq.push({matrix[i][0],i,0});
            }
        }
        while(!pq.empty()){
            auto[val,row,col]=pq.top();
            ans=val;//stores the val of the last popped element.
            pq.pop();//pops the smallest element from pq.
            count++;
            if(count==k) break;
            if(col<m-1){
                pq.push({matrix[row][col+1],row,col+1});
            }
        }
        return ans;

    }
};