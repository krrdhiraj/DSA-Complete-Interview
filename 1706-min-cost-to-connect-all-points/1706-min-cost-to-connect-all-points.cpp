class Solution {
    public:

    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x,  int y){
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y)
            return ;
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
    int kruskal(vector<vector<int>> &adj){
        int sm = 0;
        for(auto &temp : adj){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if(parent_u != parent_v){
                sm += wt;
                Union(u,v);
            }
        }
        return sm;
    }
    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = points.size();

        parent.resize(n);
        rank.resize(n, 0);
        // making adj
        vector<vector<int>> adj;
        for(int i = 0; i<n; i++){
            parent[i] = i;
            for(int j = i+1; j<n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x1-x2) + abs(y1-y2);

                adj.push_back({i, j, dist});
                adj.push_back({j, i, dist});
            }
        }
        auto comparator = [&](auto &v1, auto &v2){
            return v1[2] < v2[2];
        };
        sort(begin(adj), end(adj), comparator);

        return kruskal(adj);
    }
};