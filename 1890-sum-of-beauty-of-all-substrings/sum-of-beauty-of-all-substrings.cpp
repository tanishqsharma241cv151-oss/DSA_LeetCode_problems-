class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            vector<int>arr(26,0);
            for(int j=i;j<n;j++){
                int maxi=0,mini=INT_MAX;
                arr[s[j]-'a']++;
                for(auto it:arr){
                    if(it>0){
                        maxi=max(maxi,it);
                        mini=min(mini,it);
                    }
                }
                if(maxi>0 && mini>0){
                    count+=maxi-mini;
                }
                   
            }
        }
        return count;
    }
};