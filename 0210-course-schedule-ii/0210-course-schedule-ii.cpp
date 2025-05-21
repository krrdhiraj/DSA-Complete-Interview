class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<bool> &inRecursion, stack<int> &st){
        visited[u] = true;
        inRecursion[u] = true;

        for(int &v : adj[u]){
            if(inRecursion[v] == true){
                hasCycle = true;
                return;
            }
            if(!visited[v]){
                DFS(adj, v, visited, inRecursion, st);
            }
        }
        st.push(u);
        inRecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        vector<int> res;
        for(auto &vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            // u ---> v
            adj[u].push_back(v);
        }
        stack<int> st;
        hasCycle = false;
        for(int u = 0; u<numCourses; u++){
            if(!visited[u]){
                DFS(adj, u, visited, inRecursion, st);
            }
        }
        
        if(hasCycle){
            return {};
        }
    
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};