class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans(2*n);
       int j = n;
       for(int i = 0; i<n; i++){
        ans[i] = nums[i];
        ans[j++] = nums[i]; 
       }
       return ans;

    }
};