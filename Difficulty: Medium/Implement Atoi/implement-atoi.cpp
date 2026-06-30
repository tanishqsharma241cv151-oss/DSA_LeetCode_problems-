class Solution {
  public:
    int myAtoi(string &s) {
        int n=s.size();
        int num=0;
        int sign=1;
        int i=0;
        while(s[i]==' '){i++;continue;}
        if(i<n && s[i]=='-'){i++;sign*=-1;}
        else if(i<n && s[i]=='+'){i++;}
        while(i<n && isdigit(s[i])){
            int digi=s[i]-'0';
            if(num>(INT_MAX-digi)/10){
                return sign==-1?INT_MIN:INT_MAX;
            }
            num=num*10+digi;
            i++;
        }
        return num*sign;
    }
};
