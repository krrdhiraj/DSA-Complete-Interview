class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<pair<int,int>> zeros;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                    zeros.push_back({i,j});
                }
            }
        }
        for(auto &p : zeros){
            int i = p.first;
            int j = p.second;
            int new_j = j;
                    int new_i = i;
                    while(new_j < n){
                        matrix[i][new_j] = 0;
                        new_j++;
                    }
                    new_j = j;
                    while(new_j >= 0){
                        matrix[i][new_j] = 0;
                        new_j--;
                    }
                    while(new_i < m){
                        matrix[new_i][j] = 0;
                        new_i++;
                    }
                    new_i = i;
                    while(new_i >= 0){
                        matrix[new_i][j] = 0;
                        new_i--;
                    }
        }
    }
};