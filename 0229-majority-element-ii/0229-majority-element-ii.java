class Solution {
    public List<Integer> majorityElement(int[] nums) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        for(int i = 0; i<n; i++){
            int cnt = 1;
            while(i+1 < n && nums[i] == nums[i+1]){
                cnt++;
                i++;
            }
            if(cnt > n/3)
               ans.add(nums[i]);

        }
        return ans;
    }
}