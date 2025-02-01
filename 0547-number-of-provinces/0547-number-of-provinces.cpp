class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj,int u, vector<bool> &visited){
        visited[u] = true;
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        // make adjacency list
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(isConnected[u][v] == 1){ // connected haai
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }
        int provinces = 0;
        // call DFS and count provinces
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                provinces++;
                DFS(adj, i, visited);
            }
        }
        return provinces;
    }
};