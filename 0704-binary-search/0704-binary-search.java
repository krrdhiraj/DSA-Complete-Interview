class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n;
        // if(n == 1){
        //     return target == nums[0] ? 0 : -1;
        // }
        while(left < right){
            int mid = (right + left)/2;
            if(nums[mid] == target){
                return  mid;
            }
            else if(target < nums[mid]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return -1;
    }
}