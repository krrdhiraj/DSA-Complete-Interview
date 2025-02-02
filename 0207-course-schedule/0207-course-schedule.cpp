class Solution {
public:
    bool topoSortBFS(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){
        queue<int> que; 
        int cnt =0; // keep track of how many nodes(vertices) i've visited
        // push all the vertices into que whose indegree = 0
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                que.push(i);
                cnt++;
            }
        }
        // apply Khan's Algorithm : to find cycle in graph
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    cnt++;
                    que.push(v);
                }
            }
        }  
        return cnt == n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        // adjacency list
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
            // calculating indegree
            indegree[v]++;
        }
        //  cycle is present , means not possible to complete all the courses.
        return topoSortBFS(adj, numCourses, indegree);
    }
};