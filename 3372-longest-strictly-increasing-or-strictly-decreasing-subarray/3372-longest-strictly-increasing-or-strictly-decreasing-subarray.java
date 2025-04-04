class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int len = 1;
        int incr = 1, decr = 1;
        int n = nums.length;
        for(int i = 1; i<n; i++){
            // check for strictly increasing..
            if(nums[i-1] < nums[i]){
                incr++;
                decr = 1;
                len = Math.max(incr,len);
            }else if(nums[i-1] > nums[i]){// strictly decreasing
                decr++;
                incr = 1;
                len = Math.max(decr,len);
            }else{ // both are equal
                incr = 1;
                decr = 1;
            }
        }
        return len;
    }
}