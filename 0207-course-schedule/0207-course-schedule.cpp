class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecur){
        visited[u] = true;
        inRecur[u] = true;
        for(int &v : adj[u]){
            if(!visited[v] && DFS(adj, v, visited, inRecur)){
                return true;
            }else if(inRecur[v]){
                return true;
            }
        }
        inRecur[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> inRecur(numCourses, false);
        unordered_map<int, vector<int>> adj;
        
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
            
        }
        int cnt = 0;
        for(int u = 0; u<numCourses; u++){
            if(!visited[u] ){
               if(DFS(adj, u, visited, inRecur)){
                return false;
               }
            }
        }
        return true;
    }
};