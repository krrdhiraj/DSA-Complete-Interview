class Solution {
    public long countSubarrays(int[] nums, long k) {
        long ans = 0;
        int n = nums.length;
        int i = 0, j =  0;
        long sum = 0;
        while(j < n){
            sum += nums[j];
            while(i<= j && sum*(j-i+1) >= k){
                sum -= nums[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
}