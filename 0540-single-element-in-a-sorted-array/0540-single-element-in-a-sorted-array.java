class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;

        int low = 0, h = n-1;
        while(low < h){
            int mid = (low + h)/2;
            int rightSz = h-mid;

            if(nums[mid] == nums[mid+1]){
                rightSz -= 1;
                if((rightSz % 2) == 0){ // right side me even element hai, single element not possible
                    h = mid-1;
                }else{
                    low = mid+2;
                }
            }else{
                if(rightSz % 2 == 0){ // right side me even element hai, single element is possible
                    h = mid;
                }else{
                    low = mid+1;
                }
            }
        }
        return nums[low];
    }
}