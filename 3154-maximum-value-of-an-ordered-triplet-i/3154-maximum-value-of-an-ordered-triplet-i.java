class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length;
        long ans = 0;
        
        int maxDiff = 0, maxI = 0;
        // calculate the max triplets
        for(int i = 0; i<n ; i++){
            ans = Math.max(ans, (long)maxDiff*nums[i]);
            maxDiff = Math.max(maxDiff, maxI - nums[i]);
            maxI = Math.max(maxI, nums[i]);
        }
        return ans;
    }
}