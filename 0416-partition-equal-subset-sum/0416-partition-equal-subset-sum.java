class Solution {
    int n ;
    int[][] dp = new int[201][20001];
    public boolean solve(int[] nums, int i, int currSm){
        if(currSm == 0)
            return true;
        if(i >= n)
            return false;

        if(dp[i][currSm] != -1){
            return dp[i][currSm] == 1;
        }

        boolean take = false;
        if(currSm >= nums[i]){
            take = solve(nums, i+1, currSm - nums[i]);
        }
        boolean notTake = solve(nums, i+1, currSm);

        dp[i][currSm] = (take || notTake) ? 1: 0;
        return take || notTake;
    }
    public boolean canPartition(int[] nums) {
        n = nums.length;
        int sm = 0;
        for(int val : nums){
            sm += val;
        }
        if(sm % 2 != 0)
            return false;

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return solve(nums, 0, sm/2);
    }
}