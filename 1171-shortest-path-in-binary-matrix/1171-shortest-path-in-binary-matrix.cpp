class Solution {
public:
    vector<vector<int>> directions{{0,1}, {0,-1}, {-1,0}, {1,0}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(m == 0 || n == 0 || grid[0][0] != 0){
            return -1;
        }
        auto isSafe = [&](int x_, int y_){
            return x_>=0 && x_ < m && y_ >= 0 && y_ < n;
        };
        
        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0] = 1;

        int pathLen = 0;
        while(!que.empty()){
            int sz = que.size();

            while(sz--){
                auto p = que.front();
                que.pop();

                int x = p.first;
                int y = p.second;

                if( x == m-1 && y == n-1)
                    return pathLen+1;

                for(auto &dir : directions){
                    int x_= x + dir[0];
                    int y_ = y + dir[1];

                    if(isSafe(x_,y_) && grid[x_][y_] == 0){
                        que.push({x_,y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            pathLen += 1;
        }
        return -1;

    }
};