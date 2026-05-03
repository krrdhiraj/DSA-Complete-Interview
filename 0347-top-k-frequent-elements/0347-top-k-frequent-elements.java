
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();

        for(int num : nums){
            mp.put(num, mp.getOrDefault(num,0)+1);
        }
        PriorityQueue<Map.Entry<Integer,Integer>> maxHeap = new PriorityQueue<>((a,b)->(b.getValue())-(a.getValue()));
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()){
            maxHeap.offer(entry);
        }

        int[] ans = new int[k];
        int i = 0;
        while(i<k){
            Map.Entry<Integer,Integer> entry = maxHeap.poll();
            ans[i++] = entry.getKey();
        }
        return ans;
    }
}