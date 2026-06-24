class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        //high and low will be on the nearby indexes to answer.
        return low+k; 
        //arr[high]+missing doesnt work because in some cases high=-1,so an alternate formula is found,check notes for derivation.
    }
};