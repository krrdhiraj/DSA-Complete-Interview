class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        int n = nums.length;
        Set<Integer> st = new HashSet<>();
        int i = 0, j = 0;
        while(j < n){
            if(Math.abs(i-j) > k){
                st.remove(nums[i]);
                i++;
            }
            if(st.contains(nums[j])){
                return true;
            }
            st.add(nums[j]);
            j++;
        }
        return false;
    }
}