class Solution {
    public void recursion(int[] nums, int idx, List<Integer> temp, List<List<Integer>> ans){
        if(idx >= nums.length){
            if(!ans.contains(temp))
                ans.add(new ArrayList<>(temp));
            return ;
        }
        temp.add(nums[idx]);
        recursion(nums, idx+1, temp, ans);
        temp.remove(temp.size()-1);
        recursion(nums, idx+1, temp, ans);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(nums);
        recursion(nums, 0, temp, ans);
        return ans;
    }
}