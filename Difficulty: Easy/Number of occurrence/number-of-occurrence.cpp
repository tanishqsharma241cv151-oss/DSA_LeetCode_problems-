class Solution {
  public:
    int firstoccurrence(vector<int>&arr,int n,int target){
        int low=0,high=n-1,first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return first;
    }
    int lastoccurrence(vector<int>&arr,int n,int target){
        int low=0,high=n-1,last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(arr[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return last;
    }
    int countFreq(vector<int>& arr, int target) {
        int n=arr.size();
        int first=firstoccurrence(arr,n,target);
        if(first==-1) return 0;
        int last=lastoccurrence(arr,n,target);
        return last-first+1;
        
    }
};
