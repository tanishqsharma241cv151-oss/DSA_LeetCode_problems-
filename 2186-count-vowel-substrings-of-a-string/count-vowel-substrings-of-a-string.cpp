class Solution {
public:
    int func(string word,int r){
        if(word[r]=='a') return 0;
        if(word[r]=='e') return 1;
        if(word[r]=='i') return 2;
        if(word[r]=='o') return 3;
        if(word[r]=='u') return 4;
        return -1;
    }
    int countVowelSubstrings(string word) {
        //total number of substrings - number of substrings with consonants.
        int r=0,l=0,count=0,n=word.size();
        vector<int>hash(5,-1);
        while(r<n){
            if(word[r]!='a'&&word[r]!='e'&&word[r]!='i'&&word[r]!='o'&&word[r]!='u'){
                //if we encounter a consonant we reset the hash vector and move l.
                fill(hash.begin(),hash.end(),-1);//resetting hash vector to all -1's.
                l=r+1;
            }
            else{
                hash[func(word,r)]=r;
                if(hash[0]!=-1&&hash[1]!=-1&&hash[2]!=-1&&hash[3]!=-1&&hash[4]!=-1){
                    //we have found the min window which contains all 5 vowels.
                    int a=min({hash[0],hash[1],hash[2],hash[3],hash[4]});
                    count+=a-l+1;
                }
            }
            r++;
        }
        return count;
    }
};