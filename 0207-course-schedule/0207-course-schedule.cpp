class Solution {
public:
    bool DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<int> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(int &v : adj[u]){
            if(!visited[v] && DFS(adj, v, visited, inRecursion)){
                return true;
            }else if(inRecursion[v]){
                return true;
            }
        }
        inRecursion[u] = false;
       return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        int n = prerequisites.size();
        vector<int> inRecursion(numCourses, false);
        unordered_map<int, vector<int>> adj;
        // adjacency list
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
        }
        for(int u = 0; u < numCourses; u++){
            if(!visited[u]){
                if(DFS(adj, u,visited, inRecursion))
                    return false;
            }
        }
        
        return true;
    }
};