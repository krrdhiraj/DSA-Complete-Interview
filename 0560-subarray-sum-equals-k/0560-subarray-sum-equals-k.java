class Solution {
    // Brute Force Approach
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        for(int i = 0; i<n; i++){
            int sm = 0;
            for(int j = i; j<n; j++){
                sm += nums[j];
                if(sm == k){
                    ans += 1;
                }
            }
        }
        return ans;
    }
}