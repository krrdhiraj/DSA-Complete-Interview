class Solution {
    public boolean helpr(int[] nums, int s, int e){
        for(int i = s; i<e; i++){
            if(nums[i] > nums[i+1])
                return false;
        }
        return true;
    }
    public boolean check(int[] nums) {
        int ind = 0;
           while(ind < nums.length && nums[0] >= nums[nums.length-1]){
               int t = nums[0];
               for(int i = 0; i<nums.length-1; i++){
                   nums[i] = nums[i+1];
               }
               nums[nums.length-1] = t;
               ind++;
           }
            return helpr(nums, 0, nums.length-1);
       }
}