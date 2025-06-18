class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n-2; i+=3){
            if(nums[i+2]-nums[i] > k){
                ans.clear();
                return ans;
            }
            vector<int> v;
            v.push_back(nums[i]);
            v.push_back(nums[i+1]);
            v.push_back(nums[i+2]);
            ans.push_back(v);
        }
        return ans;
    }
};