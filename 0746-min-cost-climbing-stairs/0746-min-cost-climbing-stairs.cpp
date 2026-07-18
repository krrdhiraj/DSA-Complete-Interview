class Solution {
public:
    
    int minCost(vector<int>&cost, int n, vector<int> &mem){
        if(n < 2)   return 0;
        if(mem[n] != -1)    return mem[n];
        return mem[n] = min(cost[n-1] + minCost(cost, n-1,mem) , cost[n-2] + minCost(cost, n-2,mem));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n < 2)
            return 0;
        vector<int> mem(n+1, -1);
        return minCost(cost, n, mem);
    }
};