class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{{0,1}, {0,-1}, {-1,0}, {1,0}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0){
            return -1;
        }
    
        queue<P> pq;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        res[0][0] = 1;
        pq.push({1, {0,0}});

        while(!pq.empty()){
            int d = pq.front().first;
            auto node = pq.front().second;
            pq.pop();

            int x = node.first;
            int y = node.second;

            for(auto &dir : directions){
                int x_ = dir[0]+x;
                int y_= dir[1] + y;

                int dist = 1;

                if((x_ >= 0 && x_ < m && y_ >= 0 && y_ < n) && grid[x_][y_] == 0 && d + dist < res[x_][y_]){
                    res[x_][y_] = d + dist;
                    pq.push({d+dist, {x_, y_}});
                }
            }
        }
        if(res[m-1][n-1] == INT_MAX)
            return -1;
        return res[m-1][n-1];
    }
};