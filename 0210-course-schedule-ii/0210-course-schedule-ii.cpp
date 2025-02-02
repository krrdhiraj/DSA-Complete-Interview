class Solution {
public:
    void BFSTopologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& res,  vector<int>& indegree){
        queue<int> que;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int u = que.front();
            que.pop();
            res.push_back(u);
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    que.push(v);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency list
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        // edge (u ---> v)
        for(vector<int> &preq : prerequisites){
            int v = preq[0];
            int u = preq[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int> ans;
        // if topological sort is possible then we can complete all the courses otherwise not
       
        BFSTopologicalSort(adj, numCourses, ans, indegree);
        
        if(ans.size() != numCourses){
            ans.clear();
        }
        return ans;
    }
};