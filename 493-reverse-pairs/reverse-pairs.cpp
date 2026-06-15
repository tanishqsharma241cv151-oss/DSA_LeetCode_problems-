class Solution {
public:
    int merge(vector<int>&nums,int low,int mid,int high){
        int count=0;
        int left=low,right=mid+1;
        int j=mid+1;
        for(int i=low;i<=mid;i++){ 
            while(j<=high && nums[i]>2LL*nums[j]){
                j++;
            }
            count+=j-(mid+1);    
        }
        //normal merge sort.
        vector<int>temp;
        while(left<=mid && right<=high){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                temp.push_back(nums[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
        return count;
    }
    int ms(vector<int>&nums,int low,int high){
        int count=0;
        if(low>=high){return count;}
        int mid=(low+high)/2;
        count+=ms(nums,low,mid);
        count+=ms(nums,mid+1,high);
        count+=merge(nums,low,mid,high);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return ms(nums,0,n-1);
    }
};