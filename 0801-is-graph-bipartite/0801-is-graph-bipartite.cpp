class Solution {
public:
    int currColor = 1;
    bool DFS(vector<vector<int>>& adj, int u, vector<int>& color){
        color[u] = currColor;

        for(int &v : adj[u]){
            if(color[v] == color[u]){
                return false;
            }
            if(color[v] == -1){
                currColor = 1 - color[u];
                if(DFS(adj, v, color) == false){
                    return false;
                }
            }
        }
        return true;
}
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> color(n, -1);

        for(int u = 0; u<n; u++){
            if(color[u] == -1){
                if(DFS(adj, u, color) == false)
                    return false;
            }
        }
        return true;
    }
};