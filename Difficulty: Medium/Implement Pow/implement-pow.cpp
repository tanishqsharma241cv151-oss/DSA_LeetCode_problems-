class Solution {
  public:
    double power(double b, int e) {
        double ans=1;
        if(e<0){
            b=1/b;
        }
        e=abs(e);
        long num=e;
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
};