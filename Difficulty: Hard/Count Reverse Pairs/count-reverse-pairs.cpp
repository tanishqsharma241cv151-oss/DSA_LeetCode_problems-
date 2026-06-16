class Solution {
  public:
    int merge(vector<int>&arr,int low,int mid,int high){
        int count=0;
        int left=low,right=mid+1;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && arr[i]>2LL*arr[j]){
                j++;
            }
            count+=j-(mid+1);
        }
        //normal merge sort;
        vector<int>temp;
        while(left<=mid && right<=high){
            if(arr[left]>arr[right]){
                temp.push_back(arr[right]);
                right++;
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
        if(low>=high){return count;}
        int mid=(low+high)/2;
        count+=ms(arr,low,mid);
        count+=ms(arr,mid+1,high);
        count+=merge(arr,low,mid,high);
        return count;
    }
    int countRevPairs(vector<int> &arr) {
        int n=arr.size();
        return ms(arr,0,n-1);
    }
};