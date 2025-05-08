class Solution {
public:
   // TC : (m*n)log(m*n)
    vector<vector<int>> directions{{0,1}, {1,0}, {0,-1}, {-1, 0}};
    typedef pair<int, pair<int,int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size(), n = moveTime[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> result(m, vector<int>(n,INT_MAX));
        result[0][0] = 0;
        
        while(!pq.empty()){
            int currTime = pq.top().first;
            pair<int,int> cell = pq.top().second;
            pq.pop();

            int i = cell.first;
            int j = cell.second;
            if(i == m-1 && j == n-1){
                return currTime ;
            }

            for(auto &dir : directions){
                int newI = i + dir[0];
                int newJ = j + dir[1];

                if(newI >= 0 && newI < m && newJ >= 0 && newJ < n){
                    int moveTme = (newI + newJ) % 2 == 0 ? 2 : 1;

                    int waitTime = max(0, moveTime[newI][newJ] - currTime);
                    int arrivalTime = waitTime + currTime + moveTme;

                    if(arrivalTime < result[newI][newJ] ){
                        result[newI][newJ] = arrivalTime;
                        pq.push({arrivalTime,{newI,newJ}});
                    }
                }
            }
        }
        return -1;
    }
};