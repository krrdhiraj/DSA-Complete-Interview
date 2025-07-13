class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int n = nums.length;
        
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                ans = Math.max(ans, cnt);
                cnt = 0;
            }else
                cnt++;
        }
        ans = Math.max(cnt, ans);
        return ans;
    }   
}