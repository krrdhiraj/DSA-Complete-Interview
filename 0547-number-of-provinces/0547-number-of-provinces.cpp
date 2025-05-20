class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited){
        if(visited[u]){
            return ;
        }
        visited[u] = true;
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // make adjancecy list
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

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