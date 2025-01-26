class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int p = Integer.MIN_VALUE;

        for(int i = 0; i<n; i++){
            int product = nums[i];
            p = Math.max(p, product);
            for(int j = i+1; j <n ; j++){
                product *= nums[j];
                p = Math.max(product,p);
            }
        }
        return p;
    }
}