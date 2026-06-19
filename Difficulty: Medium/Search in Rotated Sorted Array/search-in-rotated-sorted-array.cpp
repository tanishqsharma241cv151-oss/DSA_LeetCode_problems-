class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==key) return mid;
            else{ //left part is sorted
                if(arr[low]<=arr[mid]){
                    if(arr[low]<=key && key<=arr[mid]){
                        high=mid-1;
                    }
                    //key is present in the unsorted right part
                    else{
                        low=mid+1;
                    }
                }
                //right part is sorted
                else{
                    if(arr[mid]<=key && key<=arr[high]){
                        low=mid+1;
                    }
                    //key is present int he unsorted left part
                    else{
                        high=mid-1;
                    }
                }
            }
        }
        return -1;
        
    }
};