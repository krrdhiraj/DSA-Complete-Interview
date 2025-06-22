class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{{1,0}, {-1, 0}, {0, 1}, {0, -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq;
        res[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()) {
            int diff  = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            int x = node.first;
            int y = node.second;
            if(x == m-1 && y == n-1)
                return diff;
            
	    for(auto dir:directions) {
		int x_   = x + dir[0];
		int y_   = y + dir[1];

		if(x_>=0 && x_<m && y_>=0 && y_<n) {

		    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
		    if(res[x_][y_] > newDiff) {
			res[x_][y_] = newDiff;
			pq.push({res[x_][y_], {x_, y_}});
		    }
		  }
	     }
        }
        return res[m-1][n-1];
    }
};