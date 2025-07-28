class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i<n; i++){
            if(intervals[i][0] <= ans.back()[1]){
                int start = min(intervals[i][0], ans.back()[0]);
                ans.back()[0] = start;
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};