class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        //implementing a min heap.
        priority_queue<int,vector<int>,greater<int>>pq;
        //keep exactly k elements in the heap at one time.
        int i=0,j=0;
        while(i<arr.size()){
            pq.push(arr[i]);
            if(pq.size()>k){
                arr[j]=pq.top();
                pq.pop();
                j++;
            }
            i++;
        }
        //put all the remaining pq elements into the array.
        while(j<arr.size()){
            arr[j]=pq.top();
            pq.pop();
            j++;
        }
    }
};