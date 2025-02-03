class Solution {
public:
    bool BFSBipartite(vector<vector<int>>& adj, int u, vector<int>& color, int currColor){
        queue<int> que;
        que.push(u);
        color[u] = currColor;

        // now traverse the graph
        while(!que.empty()){
            int curr = que.front();
            que.pop();
            for(int &v : adj[curr]){
                if(color[v] == color[curr]) // dono node ka color same ho gya not a Bipartite
                    return false;
                // if currNode ko fill hi nhi kiya ho : toh kro
                if(color[v] == -1){
                    // color of v kya hoga ? jo last node ka h usse diff
                    color[v] = 1 - color[curr];
                    que.push(v);
                }
            }
        }
        return true; // Bipartite hoga
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);

        // traverse the graph and check
        for(int u = 0; u < v; u++){
            if(color[u] == -1){ // currColor = 1
                if(BFSBipartite(graph, u, color, 1) == false)
                    return false; // not Bipartite
            }
        }
        return true;
    }
};