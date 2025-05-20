class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int, vector<int>> adj;
        
        for(auto &preq : prerequisites){
            int u = preq[1];
            int v = preq[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> que;
        int cnt = 0;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0){
                que.push(i);
                cnt++;
            }
        }
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

        return cnt == numCourses;
    }
};