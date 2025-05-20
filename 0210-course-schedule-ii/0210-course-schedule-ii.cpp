class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> adj;

         vector<int> indegree(numCourses, 0);
       // edges(u ---> v)
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        for(int i = 0; i<numCourses; i++){
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
        if(res.size() != numCourses){
            res.clear();
        }
        return res;
        
    }
};