class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
                ans.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                    ans.pop_back();
                }
                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                    ans.push_back(asteroids[i]);
                }   
                else if(st.top()>0 && st.top()==abs(asteroids[i])){
                    st.pop();ans.pop_back();
                    continue;
                }
            }
        }
        return ans;
    }
};