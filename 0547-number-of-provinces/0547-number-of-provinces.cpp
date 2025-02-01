class Solution {
public:
    void BFS(vector<vector<int>> &isConnected,int u, vector<bool> &visited){
        if(visited[u])
            return ;
        queue<int> que;
        que.push(u);

        while(!que.empty()){
            int t = que.front();
            que.pop();
            visited[t] = true;
            for(int v =0; v <isConnected.size(); v++){
                if(!visited[v] && isConnected[t][v] == 1){
                    que.push(v);
                }
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
                BFS(isConnected, i, visited);
            }
        }
        return provinces;
    }
};