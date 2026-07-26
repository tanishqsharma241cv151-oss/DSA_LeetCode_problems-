class Solution {
public:
    int longestwithflips(string answerKey,int k,int target){
        int n=answerKey.size();
        int l=0,r=0,maxlen=0;
        int flips=0;
        while(r<n){
            while(flips>k){
                if(answerKey[l]!=target) flips--;
                l++;
            }
            if(answerKey[r]!=target)flips++;
            if(flips<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;

    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int a=longestwithflips(answerKey,k,'T');
        int b=longestwithflips(answerKey,k,'F');
        return max(a,b);
    }
};