class Solution {
    public int singleNonDuplicate(int[] nums) {
        int xr = 0;
        for(int val : nums){
            xr ^= val;
        }
        return xr;
    }
}