class Solution {
    public int maxSubArray(int[] nums) {
        int sm = Integer.MIN_VALUE;
        int n = nums.length;
        int currSm = 0;
        for(int i = 0; i<n ;i++){
            currSm += nums[i];

            sm = Math.max(currSm, sm);
            if(currSm < 0){
                currSm = 0;
            }
        }
        return sm;
    }
}