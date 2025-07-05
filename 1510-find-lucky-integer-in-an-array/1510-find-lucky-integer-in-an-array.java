class Solution {
    public int findLucky(int[] arr) {
        int n = arr.length;

        HashMap<Integer,Integer> mp = new HashMap<>();

        for(int val : arr){
            mp.put(val, mp.getOrDefault(val, 0)+1);
        }
        int ans = -1;
        for(Map.Entry<Integer, Integer> entry : mp.entrySet()){
            if(entry.getValue() == entry.getKey()){
                ans = Math.max(ans, entry.getKey());
            }
        }
        return ans;
    }
}