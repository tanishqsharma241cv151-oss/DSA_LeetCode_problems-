class Solution {
  public:
    double p(double b,int n){
        if(n<0){
            b=1/b;
        }
        n=abs(n);
        long  num=n;
        double ans=1;
        while(num!=0){
            if(num%2==0){
                b*=b;num/=2;
            }
            else{
                ans*=b;num--;
            }
        }
        return ans;
        
    }
    int nthRoot(int n, int m) {
        int ans=-1;
        int low=1,high=m;
        if(m==0) return 0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(p(mid,n)>m){
                high=mid-1;
            }
            else if(p(mid,n)==m){
                ans=mid;
                low=mid+1;
                return mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};