class Solution {
public:
    // Bottom up : Tablulation approach(sabse pahle base case)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 2)
            return 0;
        vector<int> dp(3); 
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i<= n; i++){
            dp[2] = min(dp[1]+cost[i-1], dp[0]+cost[i-2]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }
};