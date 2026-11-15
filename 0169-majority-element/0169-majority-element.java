class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int cnt = 1;
        Arrays.sort(nums);
        for(int i = 1; i<n; i++){
            if(nums[i-1] == nums[i]){
                cnt++;
            }else{
                if(cnt > n/2)
                    return nums[i-1];
                cnt = 1;
            }
        }
        return nums[n-1];
    }
}