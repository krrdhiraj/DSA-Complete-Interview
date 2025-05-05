class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profits = 0;
        
        for(int i = 1; i<n; i++){
           // think greedely : jab v bigger price mile bech do
           if(prices[i] > prices[i-1]){
             profits += prices[i]-prices[i-1];
           }
        }
        return profits;
    }
};