class Solution {
public:
    int f(vector<int>&nums,int low,int high,int target){
        int n=nums.size();
        if(low>high){return -1;}
        int mid=(low+high)/2;
        if(nums[mid]==target){return mid;}
        else if(nums[mid]<target){return f(nums,mid+1,n-1,target);}
        else{
            return f(nums,low,mid-1,target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return f(nums,0,n-1,target);    
    }
};