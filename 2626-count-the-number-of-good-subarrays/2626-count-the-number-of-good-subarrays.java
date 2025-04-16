class Solution {
    public long countGood(int[] nums, int k) {
        long ans = 0, pairs = 0;
        Map<Integer,Integer> mp = new HashMap<>();
        int n = nums.length;
        int i = 0, j = 0;

        while(j < n){
            pairs += mp.getOrDefault(nums[j],0);
            mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);

            while(pairs >= k){
                ans += (n-j);
                mp.put(nums[i], mp.get(nums[i])-1);
                pairs -= mp.get(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
}