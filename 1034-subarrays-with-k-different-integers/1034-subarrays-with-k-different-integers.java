class Solution {
     
    public int subarraysWithKDistinct(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        Map<Integer,Integer> mp = new HashMap<>();
        int i = 0, j = 0;
        int lastIdxOfI = 0;
        while(j < n){
            mp.put(nums[j], mp.getOrDefault(nums[j],0) + 1);
            // invalid subarray or window
            while(mp.size() > k){
                mp.put(nums[i], mp.get(nums[i])-1);
                if(mp.get(nums[i]) == 0){
                    mp.remove(nums[i]);
                }
                i++;
                lastIdxOfI = i;
            }

            // shrink the window : find min length valid subarr
            while(mp.get(nums[i]) > 1){
                mp.put(nums[i], mp.get(nums[i])-1);
                i++;
            }

            // count the valid subarr 
            if(mp.size() == k)
                ans += (i - lastIdxOfI +1);
            j++;
        }
        return ans;
    }
}