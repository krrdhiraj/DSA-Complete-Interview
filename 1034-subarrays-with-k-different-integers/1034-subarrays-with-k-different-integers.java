class Solution {
     public int slidingWindow(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        Map<Integer,Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        while(j < n){
            mp.put(nums[j], mp.getOrDefault(nums[j],0) + 1);
            while(mp.size() > k){
                mp.put(nums[i], mp.get(nums[i])-1);
                if(mp.get(nums[i]) == 0){
                    mp.remove(nums[i]);
                }
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k-1);
    }
}