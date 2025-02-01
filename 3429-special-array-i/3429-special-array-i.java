class Solution {
    public boolean isArraySpecial(int[] nums) {
        int n = nums.length;
        if(n <= 1)
            return true;
        for(int i = 1; i<n; i++){
            int first = nums[i-1] %2;
            int second = nums[i] %2;
            if((first == 0 && second == 0) || (first != 0 && second != 0))
                return false;
            
        }
        return true;
    }
}