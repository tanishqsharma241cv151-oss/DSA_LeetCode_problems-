class Solution {
  public:
    int countDigits(int n) {
        int dig=0;
        while(n>0){
            n/=10;
            dig++;
        }
        return dig;
    }
};