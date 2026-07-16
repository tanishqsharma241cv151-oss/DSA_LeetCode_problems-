class Solution {
public:
    vector<int>findnse(vector<int>&nums){
        int n=nums.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]<=nums[st.top()]){ // <= to avoid duplicates.
                st.pop();
            }
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>findpse(vector<int>&nums){
        int n=nums.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[i]<nums[st.top()]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>findnge(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>nge(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[i]>=nums[st.top()]){ // >= to avoid duplicates.
                st.pop();
            }
            nge[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>findpge(vector<int>&nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pge(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&nums[i]>nums[st.top()]){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return pge;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse=findnse(nums);vector<int>pse=findpse(nums);
        vector<int>nge=findnge(nums);vector<int>pge=findpge(nums);
        long long suml=0,sums=0,range=0;
        long long l1=-1,r1=-1;
        long long l2=-1,r2=-1;
        for(int i=0;i<n;i++){
            l1=i-pse[i];r1=nse[i]-i;
            sums=sums+(l1*r1*nums[i]*1LL);
            l2=i-pge[i];r2=nge[i]-i;
            suml=suml+(l2*r2*nums[i]*1LL);
            range=(long long)(suml-sums);
        }
        return range;

    }
};