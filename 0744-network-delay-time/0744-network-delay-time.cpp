class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        // adj list created
        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            adj[u].push_back({v, w});
        }
        // by using Dijkastra's Algo will find the min time taken to reach all nodes
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      
        vector<int> res(n+1, INT_MAX);
        res[k] = 0;
        pq.push({k, 0}); // {node, time}

        while(!pq.empty()){
            int node = pq.top().first;
            int dist = pq.top().second;
            pq.pop();

            for(auto &it : adj[node]){
                int u = it.first;
                int d = it.second;

                if(d + dist < res[u]){
                    res[u] = d + dist;
                    pq.push({u,d+dist});
                }
            }
        }
        int ans = -1;
        for(int i = 1; i<n+1; i++){

            ans = max(ans, res[i]);
        }
        return ans == INT_MAX? -1 : ans;
    }
};