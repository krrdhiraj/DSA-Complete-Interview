class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int low = 0, h = n-1;

        while(low <= h){
            int mid = (low+h)/2;
            if(nums[mid] == target)
                return true;
            if(nums[low] == nums[mid] && nums[mid] == nums[h]){
                low++;
                h--;
                continue;
            }
            if(nums[mid] <= nums[h]){// right part is sorted
                if(nums[mid] <= target && target <= nums[h]){
                    low = mid+1;
                }else{
                    h = mid-1;
                }
            }else if(nums[low] <= nums[mid]){ // left part is sorted
                if(nums[low] <= target && target <= nums[mid]){
                    h = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }
        return false;
    }
}