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

           if(mp.containsKey(cummSm-k)){
             ans += mp.get(cummSm-k);
           }
           mp.put(cummSm, mp.getOrDefault(cummSm, 0) + 1);
        }
        return ans;
    }
}