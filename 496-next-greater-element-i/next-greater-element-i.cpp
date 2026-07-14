class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //first find out the nge for all the elements in nums2, store them in a hashmap;
        stack<int>st;
        int n1=nums1.size(),n2=nums2.size();
        unordered_map<int,int>mpp;
        vector<int>arr;
        for(int i=n2-1;i>=0;i--){
            if(st.empty()){
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);}
            else{
                if(nums2[i]<st.top()){
                    mpp[nums2[i]]=st.top();
                    st.push(nums2[i]);
                }
                else{
                    while(!st.empty()&&nums2[i]>=st.top()){st.pop();}
                    if(st.empty()){
                        mpp[nums2[i]]=-1;
                        st.push(nums2[i]);
                    }
                    else{
                        mpp[nums2[i]]=st.top();
                        st.push(nums2[i]);
                    }
                }
            }
        }
        for(int i=0;i<n1;i++){
            arr.push_back(mpp[nums1[i]]);
        }
        return arr;

    }
};