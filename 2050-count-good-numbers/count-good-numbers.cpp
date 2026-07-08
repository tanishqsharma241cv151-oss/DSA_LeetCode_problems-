class Solution {
public:
    long long pow(long long x,long long n){
        long long mod=1e9+7;
        long long ans=1;
        if(n==0) return 1;
        while(n>0){
            if(n%2==0){
                x=(x*x)%mod;
                n/=2;
            }
            else{
                ans*=x;
                ans%=mod;
                n--;
            }
        }
        ans%=mod;
        return ans;
        
    }
    int countGoodNumbers(long long n) {
        long long mod=1e9+7;
        return((pow(5,n/2+n%2)* pow(4,n/2)))%mod;
    }
};