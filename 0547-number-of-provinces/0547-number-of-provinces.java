class Solution {
    int n ;
    public void DFS(int[][] isConnected, int u, boolean[] visited){
        visited[u] = true;
        // visit neighbours
        for(int v = 0; v <n; v++){
            if(visited[v] == false && isConnected[u][v] == 1){
                DFS(isConnected, v, visited);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        n = isConnected.length;
        boolean[] visited = new boolean[n];
        
        int provinces = 0;
        // call DFS and count provinces
        for(int u = 0; u < n; u++){
            if(visited[u] == false){
                DFS(isConnected, u, visited);
                provinces++;
            }
        }
        return provinces;
    }
}