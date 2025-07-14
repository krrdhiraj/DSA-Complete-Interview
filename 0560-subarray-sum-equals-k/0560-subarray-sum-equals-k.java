class Solution {
    // Optimal Approach : O(n)
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        HashMap<Integer,Integer> mp = new HashMap<>();
        mp.put(0,1);
        int cummSm = 0;
        for(int i = 0; i<n; i++){
           cummSm += nums[i];
           ans += mp.getOrDefault(cummSm-k,0);
           mp.put(cummSm, mp.getOrDefault(cummSm, 0) + 1);
        }
        return ans;
    }
}