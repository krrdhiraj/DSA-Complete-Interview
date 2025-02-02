class Solution {

    public void BFS(int[][] adj, int u, boolean[] visited){
       Queue<Integer> que = new LinkedList<>();
       que.offer(u);
       while(!que.isEmpty()){
            int t = que.poll();
            visited[t] = true;
            for(int v = 0; v < adj.length; v++){
                if(!visited[v] && adj[t][v] == 1){
                    que.offer(v);
                }
            }
       }

    }
    public int findCircleNum(int[][] isConnected) {
       int n = isConnected.length;
        boolean[] visited = new boolean[n];
        
        int provinces = 0;
        // call DFS and count provinces
        for(int u = 0; u < n; u++){
            if(!visited[u]){
                provinces++;
                BFS(isConnected, u, visited);
            }
        }
        return provinces;
    }
}