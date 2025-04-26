class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();
        int cntSubArray = 0;

        mp.put(0,1);
        int sm = 0, rem = 0;
        for(int i = 0; i<n; i++){
            sm += nums[i];
            rem = sm%k;
            if(rem < 0){
                rem += k;
            }
            if(mp.containsKey(rem)){
                cntSubArray += mp.get(rem);
            }
            mp.put(rem, mp.getOrDefault(rem,0)+1);
        }
        return cntSubArray;
    }
}