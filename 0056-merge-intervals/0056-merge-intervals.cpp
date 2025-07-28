class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i<n; i++){
            if( i+1< n && intervals[i][1] >= intervals[i+1][0]){
                int start = min(intervals[i][0], intervals[i+1][0]);
                int end = max(intervals[i][1], intervals[i+1][1]);
                ans.push_back({start, end});
                i++;
            }else{
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};