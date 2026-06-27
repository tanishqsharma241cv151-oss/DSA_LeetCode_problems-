class Solution {
public:
    bool countproduct(vector<int>&nums1,vector<int>&nums2,long long k,long long mid){
        int n1=nums1.size(),n2=nums2.size(); 
        long long count=0;
        for(int i=0;i<n1;i++){
            if(nums1[i]>0){
                long long low=0,high=n2-1,pos=-1;
                while(low<=high){
                    long long j=low+(high-low)/2;
                    if((1LL)*nums1[i]*nums2[j]<=mid){ //valid js will be in the front 
                        pos=j;low=j+1;
                    }
                    else high=j-1;   
                }
                count+=pos+1;
            }
            else if(nums1[i]<0){
                long long low=0,high=n2-1,pos=0;
                while(low<=high){
                    long long j=low+(high-low)/2;
                    if((long long)nums1[i]*nums2[j]<=mid){
                        pos=n2-j,high=j-1;
                    }
                    else{
                        low=j+1;
                    }    
                }
                count+=pos;
            }
            else{
                if(0<=mid){
                    count+=n2;
                }
                else continue;
            }     
            
        }
        return count<k;
    
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long n1=nums1.size(),n2=nums2.size();
        long long low=min({1LL*nums1[0]*nums2[0],1LL*nums1[n1-1]*nums2[0],1LL*nums1[0]*nums2[n2-1],1LL*nums1[n1-1]*nums2[n2-1]});
        long long high=max({1LL*nums1[0]*nums2[0],1LL*nums1[n1-1]*nums2[0],1LL*nums1[0]*nums2[n2-1],1LL*nums1[n1-1]*nums2[n2-1]});
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(countproduct(nums1,nums2,k,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    
};