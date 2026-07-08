class Solution {
public:
    int myAtoi(string s) {
        int sum=0;
        int sign=1;
        int i=0;
        for(i=0;i<s.size();i++){
            if(s[i]==' ')continue;
            if(s[i]!=' ')break;
        }
        if(s[i]=='-'){
            sign*=(-1);i++;
        }
        else if(s[i]=='+'){
            sign*=1; i++;
        }
        while(i<s.size()){
            if(isdigit(s[i])){
                if(s[i]=='0') continue;
                int digi=s[i]-'0';
                if(sum>(INT_MAX-digi)/10){
                    return (sign<0)?INT_MIN:INT_MAX;
                }
                else{
                    sum=sum*10+digi;
                }   
            }
            else{
                break;
            }
            i++;
        }
        return sum*sign ;

        
        
    }
};