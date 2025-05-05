class Solution {
public:
    int maxProfit(vector<int>& prices) {
     
        int n = prices.size();
        int profits = 0;
        int buy = prices[0];
        for(int i = 1; i<n; i++){
            profits = max(profits, prices[i]-buy);
            buy = min(buy, prices[i]);
        }
        return profits;
    }
};