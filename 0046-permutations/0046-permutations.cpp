class Solution {
public:
    vector<vector<int>> ans;
    int n ;
    void solve(int idx, vector<int> &nums){
        if(idx >= n){
            ans.push_back(nums);
            return;
        }
        for(int i = idx; i<n; i++){
            swap(nums[idx], nums[i]); // do
            solve(idx+1, nums);       // explore
            swap(nums[idx], nums[i]); // undo
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       n = nums.size();
       solve(0, nums);
       return ans;
    }
};