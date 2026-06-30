class Solution {
  public:
    int reverseDigits(int n) {
        int k=n;
        int dig=0;
        while(k>0){
            k/=10;
            dig++;
        }
        int rev=0;
        int b=0;
        for(int i=0;i<dig;i++){
            b=n%10;
            rev=rev*10+b;
            n/=10;
        }
        return rev;
    }
};