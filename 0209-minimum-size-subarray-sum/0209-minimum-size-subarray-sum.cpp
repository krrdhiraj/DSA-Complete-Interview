class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        int i = 0, j = 0;
        // sort(begin(nums), end(nums));
        int sm = 0;
        while(j < n){
            sm += nums[j];
            if(sm >= target){
                while( sm >= target){
                    ans = min(ans, j-i+1);
                    sm -= nums[i];
                    i++;
                }
                
            }
            j++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};