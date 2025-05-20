class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited,vector<bool>& inRecursion, vector<int> &st){
        visited[u] = true;
        inRecursion[u] = true;
        for(int &v : adj[u]){
            if(inRecursion[v])
                return ;
            if(!visited[v])
                DFS(adj, v, visited,inRecursion, st);
        }
        st.push_back(u);
        inRecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> adj;

        vector<bool> inRecursion(numCourses, false);
        vector<bool> visited(numCourses, false);
       // edges(u ---> v)
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
        }
        for(int u = 0; u< numCourses; u++){
            if(!visited[u]){
                DFS(adj, u, visited,inRecursion, res);
            }
        }
        reverse(begin(res), end(res));
       
        if(res.size() != numCourses){
            res.clear();
        }
        return res;
        
    }
};