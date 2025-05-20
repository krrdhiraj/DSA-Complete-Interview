class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool> &visited){
        
        visited[u] = true;
        for(int v = 0 ; v < adj[u].size(); v++){
            if(!visited[v] && adj[u][v] == 1){
                DFS(adj, v, visited);
            }
        } 
        
    }
    int findCircleNum(vector<vector<int>>& adj) {
        // make adjancecy list
        int n = adj.size();

        vector<bool> visited(n, false);
        int countOfProvinces = 0;
        for(int u = 0 ; u<n; u++){
            if(!visited[u]){
                DFS(adj, u, visited);
                countOfProvinces++;
            }
        }

        return countOfProvinces;
    }
};