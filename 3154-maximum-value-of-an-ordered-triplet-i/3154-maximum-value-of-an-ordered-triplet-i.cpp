class Solution {
public:

    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        int maxDiff = 0, maxI = 0;
        // calculate the max triplets
        for(int i = 0; i<n ; i++){
            ans = max(ans, (long long)maxDiff*nums[i]);
            maxDiff = max(maxDiff, maxI - nums[i]);
            maxI = max(maxI, nums[i]);
        }
        return ans;
    }
};