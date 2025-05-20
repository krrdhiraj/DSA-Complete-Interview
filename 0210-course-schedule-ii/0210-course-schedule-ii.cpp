class Solution {
public:
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, stack<int> &st){
        visited[u] = true;
    
        for(int &v : adj[u]){
            if(!visited[v])
                DFS(adj, v, visited, st);
        }
        st.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
       // edges(u ---> v)
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
        }
        stack<int> st;
        for(int u = 0; u< numCourses; u++){
            if(!visited[u]){
                DFS(adj, u, visited, st);
            }
        }

        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        if(res.size() != numCourses){
            res.clear();
        }
        return res;
        
    }
};