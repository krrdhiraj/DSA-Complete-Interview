class Solution {
    // TC : O(nlog(n))
    public long countFairPairs(int[] nums, int lower, int upper) {
        long fairPairs = 0;
        int n = nums.length;

        Arrays.sort(nums); // O(nlog(n))

        int left = 0, right = n-1;
        long countPairLessThanUpper = 0;
        while(left < right){ // O(log(n))
            if(nums[left] + nums[right] <= upper){
                countPairLessThanUpper += (right - left);
                left++;
            }else{
                right--;
            }
        }
        left = 0; right = n-1;
        long lowerPairCount = 0;
        while(left < right){ // O(log(n))
            if(nums[left] + nums[right] < lower){
                lowerPairCount += (right - left);
                left++;
            }else{
                right--;
            }
        }
        fairPairs = countPairLessThanUpper - lowerPairCount;
        return fairPairs;
    }
}