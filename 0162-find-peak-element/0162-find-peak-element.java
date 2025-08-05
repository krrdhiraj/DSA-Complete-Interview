class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int idx = 0;
        int l = 0, h = n-1;

        while(l < h){
            int mid = (l+h)/2;
            if(mid-1 >= 0 && nums[mid-1] < nums[mid] && mid + 1 < n && nums[mid] > nums[mid+1]){
                return mid;
            }
            if(nums[mid] < nums[mid+1]){
                l = mid+1;
            }else{
                h = mid;
            }
        }
        return h;
    }
}