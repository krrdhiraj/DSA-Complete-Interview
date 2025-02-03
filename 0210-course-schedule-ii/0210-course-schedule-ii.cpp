class Solution {
public:
    void DFSTopologicalSort(unordered_map<int, vector<int>>& adj, int u, vector<int>& res,  vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(int &v : adj[u]){
            if(inRecursion[v] == true){
                return;
            }
            if(!visited[v]){
                DFSTopologicalSort(adj,v, res,visited , inRecursion);
            }
        }
        res.push_back(u);
        inRecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        unordered_map<int, vector<int>> adj;
        vector<int> res;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);

        // edge (u ---> v)
        for(vector<int> &preq : prerequisites){
            int v = preq[0];
            int u = preq[1];
            adj[u].push_back(v);
        }
        // if topological sort is possible then we can complete all the courses otherwise not
       for(int i = 0; i<numCourses; i++){
            if(!visited[i])
                DFSTopologicalSort(adj, i, res, visited, inRecursion);
       }
        reverse(begin(res), end(res));
        if(res.size() == numCourses){
           return res;
        }
        return {};
    }
};