class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        for(int val : nums){
            mx = Math.max(mx, val);
        }
        int l = 1; 
        int r = mx;
        while(l <= r){
            int mid = (r+l)/2;
            int sm = 0;
            for(int i = 0; i<n; i++){
                sm += Math.ceil((double)nums[i]/ (double)mid);
            }
            if(sm <= threshold){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
}