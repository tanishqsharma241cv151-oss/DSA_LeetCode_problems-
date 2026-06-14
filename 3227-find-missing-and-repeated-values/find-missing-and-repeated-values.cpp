class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        long long a=n*n;
        long long s=((a)*(a+1))/2,s2=0;;
        long long ss=((a)*(a+1)*(2*a+1)/6),ss2=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s2= s2+grid[i][j];
                ss2= ss2+grid[i][j]*grid[i][j];
            }    
        }
        long long k=s2-s;
        long long m=ss2-ss;
        long long c=m/k; 
        int repeating=(int)(k+c)/2;
        int missing=(int)repeating-k;
        return {repeating,missing};
    }
};