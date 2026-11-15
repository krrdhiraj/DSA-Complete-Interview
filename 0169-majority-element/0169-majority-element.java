class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int maj = 0, cnt = 0;
        for(int num : nums){
            if(cnt == 0){
                maj = num;
                cnt = 1;
            }else if(maj == num) cnt++;
            else cnt--;
        }
        return maj;
    }
}