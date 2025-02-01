class Solution {
    
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length, j = 0;
        int m = queries.length;
        boolean[] ans = new boolean[m];
        int[] preSm = new int[n];
        preSm[0] = 0;
        for(int i = 1; i<n; i++){
            if(nums[i]%2 == nums[i-1]%2){
                preSm[i] = preSm[i-1]+1;
            }else{
                preSm[i] = preSm[i-1];
            }
        }
        for(int i = 0; i<m; i++){
            int s = queries[i][0];
            int e = queries[i][1];
            ans[j] = (preSm[e]-preSm[s] == 0 ? true : false);
            j++;
        }
        return ans;
    }
}