class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int n = nums.size();
        Map<Integer,Long> mp = new HashMap<>();
        mp.put(0,1L);

        long sm = 0;
        long res = 0;

        for(int i = 0; i<n; i++){
            if(nums.get(i) % modulo == k){
                sm += 1;
            }
            int r1 = (int)sm % modulo;
            int r2 = (r1 - k + modulo) % modulo;

            res += mp.getOrDefault(r2, 0L);
            mp.put((int)r1, mp.getOrDefault(r1,0L)+1);
        }
        return res;
    }
}