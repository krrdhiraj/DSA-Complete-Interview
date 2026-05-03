
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();

        for(int num : nums){
            mp.put(num, mp.getOrDefault(num,0)+1);
        }
        PriorityQueue<Map.Entry<Integer,Integer>> minHeap = new PriorityQueue<>((a,b)->(a.getValue())-(b.getValue()));
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()){
            minHeap.offer(entry);
            if(minHeap.size() > k){
                minHeap.poll();
            }
        }

        int[] ans = new int[k];
        int i = 0;
        while(!minHeap.isEmpty()){
            Map.Entry<Integer,Integer> entry = minHeap.poll();
            ans[i++] = entry.getKey();
        }
        return ans;
    }
}