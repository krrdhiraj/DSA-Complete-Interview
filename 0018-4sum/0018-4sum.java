class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        Arrays.sort(nums);
        for(int i = 0; i<n-3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<n-2; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                
                int left = j+1;
                int right = n-1;
                // now apply two pointer
                while(left < right){
                    long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];

                    if(sum > target){
                        right--;
                    }else if(sum < target){
                        left++;
                    }else{
                        ans.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        while(left < right && nums[left] == nums[left+1])
                            left++;
                        while(left < right && nums[right] == nums[right-1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return ans;
    }
}