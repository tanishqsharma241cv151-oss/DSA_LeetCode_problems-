class Solution {
  public:
    int floorSqrt(int n) {
        int low=1,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if((long long)mid*mid>n) high=mid-1;
            else{low=mid+1;}
        }
        return high;
    }
};