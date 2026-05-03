
class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();

        for(int num : nums){
            mp.put(num, mp.getOrDefault(num,0)+1);
        }
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a,b)->b[0]-a[0]);
        for(Map.Entry<Integer,Integer> entry : mp.entrySet()){
            maxHeap.offer(new int[]{entry.getValue(), entry.getKey()});
        }

        int[] ans = new int[k];
        int i = 0;
        while(i<k){
            ans[i++] = maxHeap.poll()[1];
        }
        return ans;
    }
}