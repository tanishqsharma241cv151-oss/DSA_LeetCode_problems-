class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //implement a min heap using priority queue.
        priority_queue<int,vector<int>,greater<int>>pq;
        //now we will store only k elements in  pq at one time.
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        int i=k;
        while(i<nums.size()){
            pq.push(nums[i]);
            pq.pop();//pops the smallest element.
            i++;
        }
        return pq.top();
    }
};