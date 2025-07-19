class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int n = 0;
    public void swap(int a, int b, int[] nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    public void solve(int idx, int[] nums){
        if(idx >= n){
            List<Integer> temp = new ArrayList<>();
            for(int i=0;i<nums.length ;i++){
                temp.add(nums[i] );
            }
            ans.add(temp);
            return;
        }
        for(int i = idx; i<n; i++){
            swap(i, idx, nums);
            solve(idx+1, nums);
            swap(i, idx, nums);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        n = nums.length;
        solve(0, nums);
        return ans;
    }
}