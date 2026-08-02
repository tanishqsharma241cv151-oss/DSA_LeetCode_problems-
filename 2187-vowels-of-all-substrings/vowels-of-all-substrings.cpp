class Solution {
public:
    long long countVowels(string word) {
        //for each vowel find out how many substrings it is associated with.
        long long l=0,r=0,sum=0,n=word.size();
        while(r<n){
            if(word[r]=='a'||word[r]=='e'||word[r]=='i'||word[r]=='o'||word[r]=='u'){
                l=n-r; //the number of substrings that start with the vowel.
                sum+= r*(l)+l; //adding the substrings where the vowel is the starting character.
            }
            r++;
        }
        return sum;
    }
};