class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        int i=0,minlen=INT_MAX,start=-1,end=-1,currend=-1;
        while(i<n){
            int j=0;
            //after this while loop ends we'll have our end index.
            while(i<n){
                //forward scan.
                if(s1[i]==s2[j]){
                    j++;
                }
                if(j==m)break;
                i++;
            }
            if(i==n) break;
            currend=i;
            j--;
            //after this while loop ends we'll have our start index.
            while(j>=0){
                //backward scan.
                if(s1[i]==s2[j]){
                    j--;
                }
                if(j==-1) break;
                i--;
            }
            if(minlen>currend-i+1){
                minlen=currend-i+1;
                start=i;
                end=currend;
            }
            i++;
        }
        return start==-1?"":s1.substr(start,end-start+1);
            
    }
};
