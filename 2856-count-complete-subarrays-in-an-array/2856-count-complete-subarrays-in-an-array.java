class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();
        Set<Integer> st = new HashSet<>();

        for(int num : nums){
            st.add(num);
        }
        int distinct = st.size();
        int count = 0;
        int i = 0, j = 0;
        while(j < n){
            mp.put(nums[j],mp.getOrDefault(nums[j],0)+1);
            while(mp.size() == distinct){
                count += n-j;
                mp.put(nums[i],mp.get(nums[i])-1);
                if(mp.get(nums[i]) == 0){
                    mp.remove(nums[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
}