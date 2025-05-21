class Solution {
public:
    int currColor = 1;
    bool BFS(vector<vector<int>>& adj, int u, vector<int>& color){
       
        queue<int> que;
        que.push(u);
        color[u] = currColor;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(int &v : adj[u]){
                if(color[v] == color[u]){
                    return false;
                }
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    que.push(v);
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
                if(BFS(adj, u, color) == false)
                    return false;
            }
        }
        return true;
    }
};