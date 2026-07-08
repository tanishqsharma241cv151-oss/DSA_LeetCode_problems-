class Solution {
public:
    int myAtoi(string s) {
        //iterative implementation.
        int n=s.size();
        int sign=1;
        int num=0;
        int i=0;
        while(i<n){
            if(s[i]==' '){i++;}
            else break;
        }
        if(i<n && s[i]=='-'){sign*=-1;i++;}
        else if(i<n;s[i]=='+'){sign=1;i++;}
        while(i<n && isdigit(s[i])){
            int dig=s[i]-'0';
            if(num>(INT_MAX-dig)/10){
                return sign==-1?INT_MIN:INT_MAX;
            }
            num=num*10+(s[i]-'0');
            i++;  
        }
        return num*sign;
    }
};