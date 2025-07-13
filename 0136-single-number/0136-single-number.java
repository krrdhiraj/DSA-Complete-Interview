class Solution {
    public int singleNumber(int[] nums) {
        int missingNum = 0;
        for(int val : nums){
            missingNum ^= val;
        }
        return missingNum;
    }
}