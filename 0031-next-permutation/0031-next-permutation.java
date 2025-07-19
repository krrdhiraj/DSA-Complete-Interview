class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int pivot = 0;
        for(int i = n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                pivot = i;
                break;
            }
        }
        
        if(pivot != 0){
            int swapIndx = pivot;
            for(int i = n-1; i >= pivot; i--){
                if(nums[i] > nums[pivot-1]){
                    swapIndx = i;
                    break;
                }
            }
            int temp = nums[swapIndx];
            nums[swapIndx] = nums[pivot-1];
            nums[pivot-1] = temp;
        }
        int i = pivot, j = n-1;
        while(i < j){
            int temp1 = nums[j];
            nums[j] = nums[i];
            nums[i] = temp1;
            i++; 
            j--;
        }
    }
}