class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();

        for(int val : nums1){
            mp.put(val, mp.getOrDefault(val,0)+1);
        }
        for(int val : nums2){
            if(mp.containsKey(val)){
                ans.add(val);
                mp.remove(val);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}