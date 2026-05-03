class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a,b)-> b[0]-a[0]);
     
        for(int i = 0; i<points.length; i++){
            int[] point = points[i];
            int dist = (point[0]*point[0]) + (point[1]*point[1]);
            maxHeap.offer(new int[]{dist,i});
            while(maxHeap.size() > k){
                maxHeap.poll();
            }
        }
        int[][] ans = new int[k][2];
        int i = 0;
        while(!maxHeap.isEmpty()){
            int[] point = maxHeap.poll();
            int idx = point[1];
            ans[i][0] = points[idx][0];
            ans[i][1] = points[idx][1];
            i++;
        }
        return ans;
    }
}