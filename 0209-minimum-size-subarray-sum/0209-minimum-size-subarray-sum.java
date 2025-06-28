class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int i = 0, j = 0;
        int ans = Integer.MAX_VALUE;
        int sm = 0;
        while(j < n){
            sm += nums[j];

            if(sm >= target){
                while(i <= j && sm >= target){
                    ans = Math.min(ans, j-i+1);
                    sm -= nums[i];
                    i++;
                }
            }
            j++;
        }
        return ans == Integer.MAX_VALUE ? 0 : ans;
    }
}