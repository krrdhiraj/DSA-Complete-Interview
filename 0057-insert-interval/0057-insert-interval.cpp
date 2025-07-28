class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        for(; i<n; i++){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0] > newInterval[1]){
                break;
            }else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        ans.push_back(newInterval);
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};