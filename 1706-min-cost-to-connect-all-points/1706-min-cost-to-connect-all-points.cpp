class Solution {
    public:
    int primAlgo(vector<vector<pair<int,int>>> &adj, int v){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<bool> inMst(v, false);

        int sm = 0; // calculate min sum

        pq.push({0, 0});

        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(inMst[node] == true)
                continue;

            inMst[node] = true;

            sm += wt;

            for(auto &vec : adj[node]){
                int neighbor_wt = vec.second;
                int neighbor_node = vec.first;

                if(inMst[neighbor_node] == false){
                    pq.push({neighbor_wt, neighbor_node});
                }
            }
            
        }
        return sm;
    }
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();
        // making adj
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        return primAlgo(adj, n);
    }
};