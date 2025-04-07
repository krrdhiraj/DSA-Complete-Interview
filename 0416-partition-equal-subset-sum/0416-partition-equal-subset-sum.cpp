class Solution {
public:
    int n ;
    int dp[201][20001];
    bool solve(vector<int>& nums, int i, int currSm){
         if(currSm == 0){
            return true;
        }
        if(i >= n)
            return false;

        if(dp[i][currSm] != -1){
            return dp[i][currSm];
        }
         bool take = false;
        if(currSm >= nums[i])
            take = solve(nums, i+1, currSm - nums[i]) ;

        bool notTake = solve(nums, i+1, currSm);

        return dp[i][currSm] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();

        int totalSm = 0;
        for(int val : nums){
            totalSm += val;
        }
        if(totalSm % 2 != 0)
            return false;

        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, totalSm/2);
    }
};