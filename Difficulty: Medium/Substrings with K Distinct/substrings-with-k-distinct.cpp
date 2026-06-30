class Solution {
  public:
    int countSubstr(string& s, int k) {
        int n=s.size(), count=0;
        int freq1[26]={0}, freq2[26]={0};
        int j1=0, j2=0, d1=0, d2=0;
        
        for(int i=0; i<n; i++){
            // window 1: atmost(k)
            if(freq1[s[i]-'a']++==0) d1++;
            while(d1>k){
                if(--freq1[s[j1]-'a']==0) d1--;
                j1++;
            }
            
            // window 2: atmost(k-1)
            if(freq2[s[i]-'a']++==0) d2++;
            while(d2>k-1){
                if(--freq2[s[j2]-'a']==0) d2--;
                j2++;
            }
            
            // exactly k = atmost(k) - atmost(k-1)
            count += (i-j1+1) - (i-j2+1);
            // simplifies to j2-j1
        }
        return count;
    
        
    }
};