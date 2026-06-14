class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //optimal solution. Take one pointer at end of arr1[] and another at start of arr2[], compare elements and swap till all the lower elements end up on the left and all the higher elements end up on the right.

        int left=m-1,right=0;
        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;right++;
            }
            else if(nums1[left]<=nums2[right]){break;}
        }
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};
