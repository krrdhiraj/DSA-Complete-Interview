class Solution {
public:
    void solve(vector<int>& nums, int i , vector<int>& curr, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(curr);
            return ;
        }

        // not take
        solve(nums, i+1, curr, res);

         // take
         curr.push_back(nums[i]);
         solve(nums, i+1, curr, res);
         curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums, 0, curr, res);
        return res;
    }
};