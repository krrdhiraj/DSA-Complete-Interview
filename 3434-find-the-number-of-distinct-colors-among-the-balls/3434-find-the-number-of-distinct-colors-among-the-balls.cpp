class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        int diffColor = 0;
        int n = queries.size();
        unordered_map<int,int> mpBallColor;
        unordered_map<int, int> cntColor;
        for(int i = 0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(mpBallColor.find(ball)  != mpBallColor.end()){ // ball is already present
                int prevColor = mpBallColor[ball];
                mpBallColor[ball] = color;
                cntColor[prevColor]--;

                // if color == 0 , ek color kam ho gya then remove the color from map
                if(cntColor[prevColor] == 0)
                    cntColor.erase(prevColor);
            }
            mpBallColor[ball] = color;
            cntColor[color]++;
            ans.push_back(cntColor.size());
        }
        return ans;
    }
};