class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length;
        long ans = 0;
        int i = 0, j = 0;
        int maxEle = Arrays.stream(nums).max().getAsInt();
       
        int cntOfMax = 0;
        while(j < n){
            if(nums[j] == maxEle){
                cntOfMax++;
            }
            while(cntOfMax == k){
                ans += (n-j);
                if(nums[i] == maxEle ){
                    cntOfMax--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
}