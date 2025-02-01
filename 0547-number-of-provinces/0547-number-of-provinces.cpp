class Solution {
public:
    void DFS(vector<vector<int>> &isConnected,int u, vector<bool> &visited){
        visited[u] = true;
       // visit neighbours 
        for(int v = 0; v < isConnected.size(); v++){
            if(!visited[v] && isConnected[u][v] == 1){
                DFS(isConnected, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
       
        int provinces = 0;
        // call DFS and count provinces
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                provinces++;
                DFS(isConnected, i, visited);
            }
        }
        return provinces;
    }
};