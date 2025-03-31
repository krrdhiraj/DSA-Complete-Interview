class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size()-1;
        
        vector<int> pairSum(n, 0);
        for(int i = 0; i<n; i++){
            pairSum[i] = weights[i]+weights[i+1];
        }
        sort(begin(pairSum), end(pairSum));

        long long maxSm = 0, minSm = 0;
        int i = 0, j = n-1;

        while(k-- > 1){
            minSm += pairSum[i++];
            maxSm += pairSum[j--];
        }

        return (maxSm - minSm);
    }
};