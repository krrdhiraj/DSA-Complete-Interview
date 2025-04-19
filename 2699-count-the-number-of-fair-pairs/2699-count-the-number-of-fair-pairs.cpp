class Solution {
public:

//  TC -> O(nlog(n))
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long fairPairs = 0;
        int n = nums.size();

        sort(begin(nums), end(nums)); // O(nlog(n))

        int left = 0, right = n-1;
        long long countUpperPair = 0;
        while(left < right){
            if(nums[left] + nums[right] <= upper){
                countUpperPair += (right - left);
                left++;
            }else{
                right--;
            }
        }
        left = 0, right = n-1;
        long long lowerPairCount = 0;
        while(left < right){
            if(nums[left] + nums[right] < lower){
                lowerPairCount += (right - left);
                left++;
            }else{
                right--;
            }
        }
        fairPairs = countUpperPair - lowerPairCount;
        return fairPairs;
    }

};