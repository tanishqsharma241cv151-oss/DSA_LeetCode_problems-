class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-2]<nums[n-1])return n-1;
        int low=1,high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            //if mid is a the peak.
            if(nums[mid-1]<nums[mid]&&nums[mid]>nums[mid+1]) return mid;
            //if mid is on a increasing curve, peak is on the left.
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]) low=mid+1;
            //if mid is on a decreasing curve, peak is on the right.
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]) high=mid-1;
            //in case of multiple peaks,if mid is on a reverse peak we can eliminate either the left or right part doesnt matter as there are peaks on both sides.
            else{low=mid+1;}   
        }
        return -1;
    }
};