class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        if(n==0){return 1;}
        if(n<0){
            x=1/x;
        }
        long num=labs(n);
        while(num!=0){   
            if(num%2==0){
                x*=x;
                num/=2.0;
            }
            else{
                num--;
                ans*=x;
            }
        }
        return ans;
    }
};