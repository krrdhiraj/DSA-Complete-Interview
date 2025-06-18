class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int maxDiff = INT_MIN;
        for(int i = 0; i<n-1; i++){
            maxDiff = max(maxDiff, abs(nums[i+1]-nums[i]));
        }
        maxDiff = max(maxDiff, abs(nums[n-1]-nums[0]));
        return maxDiff;
    }
};