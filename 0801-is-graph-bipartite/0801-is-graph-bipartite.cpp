class Solution {
public:
    bool DFSBipartite(vector<vector<int>>& adj, int u, vector<int>& color, int currColor){
        color[u] = currColor; // filled currNode with currColor

        // now traverse the graph
        for(int &v : adj[u]){
            if(color[v] == color[u]) // dono node ka color same ho gya not a Bipartite
                return false;
            // if currNode ko fill hi nhi kiya ho : toh kro
            if(color[v] == -1){
                // color of v kya hoga ? jo last node ka h usse diff
                int colorV = 1 - color[u];
                // call the next node to fill
                if(DFSBipartite(adj, v, color, colorV) == false)
                    return false;
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
                if(DFSBipartite(graph, u, color, 1) == false)
                    return false; // not Bipartite
            }
        }
        return true;
    }
};