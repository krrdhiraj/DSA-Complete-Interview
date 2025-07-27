class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        int maj = 0;
        int cnt1 = 0, cnt2 = 0;
        int maj1 = Integer.MIN_VALUE, maj2 = Integer.MAX_VALUE;
        List<Integer> ans = new ArrayList<>();
        for(int num : nums){ // Boyer Moore voting
            if(cnt1 == 0 && maj2 != num){
                maj1 = num;
                cnt1 = 1;
            }else if(cnt2 == 0 && maj1 != num){
                maj2 = num;
                cnt2 = 1;
            }else if(maj1 == num){
                cnt1++;
            }else if(maj2 == num){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
         cnt1 = 0;cnt2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == maj1){
                cnt1++;
            }
            if(nums[i] == maj2){
                cnt2++;
            }
        }
        if(cnt1 > n/3) ans.add(maj1);
        if(cnt2 > n/3) ans.add(maj2);
        return ans;
    }
}