class Solution {
  public:
    int merge(vector<int>&arr,int low,int mid,int high){
        int count=0;
        vector<int>temp;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(arr[left]>arr[right]){
                temp.push_back(arr[right]);
                right++;
                count+=mid-left+1;
            }
            else{
                temp.push_back(arr[left]);
                left++;
            }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            arr[i]=temp[i-low];
        }
        return count;
    }
    
    int ms(vector<int>&arr,int low,int high){
        int count=0;
        int n=arr.size();
        if(low>=high){return 0;} //base condition
        int mid=(low+high)/2;
        count+=ms(arr,low,mid);
        count+=ms(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    int inversionCount(vector<int> &arr) {
        int n=arr.size();
        int count=0;
        count=ms(arr,0,n-1);
        return count;
    }
};