class Solution {
public:
    int m, n;
    vector<vector<int>> dir{{0,1}, {1,0}, {-1,0}, {0,-1}};
    bool solve(vector<vector<char>>&board, int i, int j, int idx, string word){
        if(idx == word.length()){
            return true;
        }
        if(i >= m || j >= n || i < 0 || j < 0){
            return false;
        }
        if(board[i][j] != word[idx])
            return false;
        char ch = board[i][j];
        board[i][j] = '&';
        for(vector<int> d : dir){
            int newI = i + d[0];
            int newJ = j + d[1];
            if(solve(board, newI, newJ, idx+1, word)){
                return true;
            }
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(solve(board, i, j, 0, word))
                        return true;
                }
            }
        }
        return false;
    }
};