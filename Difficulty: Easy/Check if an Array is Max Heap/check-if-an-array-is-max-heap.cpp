class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n=arr.size();
        int i=n-1;
        while(i>0){
            int parent=(i-1)/2;
            if(arr[i]>arr[parent]) return false;
            i--;
        }
        return true;
            
        
    }
};
