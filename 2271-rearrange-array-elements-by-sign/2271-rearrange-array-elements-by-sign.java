class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] positive = new int[n/2];
        int[] negative = new int[n/2];
        int pos = 0, neg = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] >= 0){
                positive[pos++] = nums[i];
            }else{
                negative[neg++] = nums[i];
            }
        }
        int k = 0;
        int i =0;
        while(k < n/2){
            nums[i++] = positive[k];
            nums[i++] = negative[k];
            k++;
        }
        return nums;
    }
}