class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int sm = 0; 
        int tempSm = 0;

        for(int i = 0; i<n; i++){
            sm += nums[i];
            tempSm += nums[i]*i;
        }

        int ans = tempSm;
        
        for(int k = 0; k<=n-1; k++){
           int temp = tempSm + sm - n*nums[n-1-k];
            ans = Math.max(temp, ans);
            tempSm = temp;
        }
        return ans;
    }
}