class Solution {
public:
    void solve(vector<string>&ans,string&num,const string&exp,int target,int ind,long currval,long residual){
        //base case;
        if(ind==num.size()){
            if(currval==target)ans.push_back(exp);
            return;
        }
        string temp="";
        long val=0; //tracks the last operand.
        for(int i=ind;i<num.size();i++){
            //skip any leading 0's, the first 0 is fine.
            if(i>ind && num[ind]=='0'){return;}
            temp+=num[i];
            val=val*10+num[i]-'0';
            if(ind==0){//for inputting the first element in the exp:-
                solve(ans,num,exp+temp,target,i+1,val,val);
            }
            else{//if exp already has a first element:-
            //recursively check for each operator:-
                solve(ans,num,exp+'+'+temp,target,i+1,currval+val,val);
                solve(ans,num,exp+'-'+temp,target,i+1,currval-val,-val);
                solve(ans,num,exp+'*'+temp,target,i+1,currval-residual+(residual*val),residual*val);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        int ind=0;
        long currval=0,residual=0;
        string exp;
        vector<string>ans;
        solve(ans,num,exp,target,ind,currval,residual);
        return ans;
    }
};