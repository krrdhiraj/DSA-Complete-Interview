class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i = 0; i<n; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()){
            if(entry.getValue() > 1){
                return entry.getKey();
            }
        }
        return -1;
    }
}