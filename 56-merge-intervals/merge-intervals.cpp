class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        for(int i=0;i<intervals.size()-1;i++){
            int start=intervals[i][0],end=intervals[i][1];
            for(int j=i+1;j<intervals.size();j++){
                if(end>=intervals[j][0] && end<intervals[j][1]){ //they are overlapping
                    end=intervals[j][1];
                    intervals[i][1]=end;
                    intervals.erase(intervals.begin()+j);
                    j--;
                }
                else if(end>=intervals[j][1]){
                    intervals.erase(intervals.begin()+j);
                    j--;
                }
                else if(end<intervals[j][0]){
                    break;
                }
            }
            
        }
        vector<vector<int>>ans(intervals.begin(),intervals.end());
        return ans;
        
    }
};