class Solution {
public:
    void recursion(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& ans){
        if(idx >= nums.size()){
            if(find(begin(ans), end(ans), temp) == ans.end())
                ans.push_back(temp);
            return ;
        }
        
        temp.push_back(nums[idx]);
        recursion(nums, idx+1, temp, ans);
        temp.pop_back();
        recursion(nums, idx+1, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(begin(nums), end(nums));
        recursion(nums, 0, temp, ans);

        return ans;
    }
};