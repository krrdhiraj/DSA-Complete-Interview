class Solution {
public:

//  TC -> O(nlog(n))
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long fairPairs = 0;
        int n = nums.size();

        sort(begin(nums), end(nums)); // O(nlog(n))

        for(int i = 0; i<n; i++){ // O(n)
            int idx = lower_bound(begin(nums)+i+1, end(nums), lower - nums[i])-begin(nums); // O(long(n))
            int numLessThanLower = idx - i -1;

            idx = upper_bound(begin(nums) + i + 1, end(nums), upper-nums[i])- begin(nums); // O(log(n))

            int numLessThanOrEqualToUpper = idx - i -1;

            fairPairs += numLessThanOrEqualToUpper - numLessThanLower;
        }

        return fairPairs;
    }

};