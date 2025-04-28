class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int cnt = 0;
        for(int i = 0; i<n-2; i++){
            int sm = nums[i]+nums[i+2];
            if(sm >= 0 && nums[i+1] < 0 || sm < 0 && nums[i+1]>= 0){
                continue;
            }
            if(nums[i+1] % 2 == 0 && sm == nums[i+1]/2){
                cnt++;
            }
        }
        return cnt;
    }
}