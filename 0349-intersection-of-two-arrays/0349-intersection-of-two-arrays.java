class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> st = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for(int val : nums1){
            st.add(val);
        }
        for(int val : nums2){
            if(st.contains(val)){
                ans.add(val);
                st.remove(val);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}