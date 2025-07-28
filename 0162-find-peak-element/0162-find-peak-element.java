class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
         int idx = 0;
        for(int i = 0; i<n-1; i++){
            if(nums[i] < nums[i+1]){
                idx = i+1;
            }
        }
        return idx;
    }
}