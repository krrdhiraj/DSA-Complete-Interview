class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int maxP = nums[0];
        for(int i = 0; i<n; i++){
            int currP = 1;
            for(int j = i; j<n; j++){
                currP *= nums[j];
                maxP = Math.max(maxP, currP);
            }
        }
        return maxP;
    }
}