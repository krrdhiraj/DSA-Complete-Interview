class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        long ans = 0;
        int maxEle = Arrays.stream(nums).max().getAsInt();
        List<Integer> maxIndx = new ArrayList<>();

        for(int i = 0; i<n; i++){
            if(nums[i] == maxEle){
                maxIndx.add(i);
            }
            int sz = maxIndx.size();
            if(sz >= k){
                int lastIdxOfMax = maxIndx.get(sz-k);
                ans += lastIdxOfMax + 1;
            }
        }
        
        return ans;
    }
}