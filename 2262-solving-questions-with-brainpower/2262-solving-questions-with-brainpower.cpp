class Solution {
public:
    int n;
    long long solveRecur(vector<vector<int>> & ques, int i, vector<long long>& dp){
        if(i >= n)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        long long taken = ques[i][0] + solveRecur(ques, i + ques[i][1] + 1, dp);
        long long not_taken = solveRecur(ques, i+1, dp);

        return dp[i] = max(taken, not_taken);
    }
    long long mostPoints(vector<vector<int>>& questions) {
       n = questions.size();
        vector<long long> dp(n, -1);
       return solveRecur(questions, 0, dp);
    }
};