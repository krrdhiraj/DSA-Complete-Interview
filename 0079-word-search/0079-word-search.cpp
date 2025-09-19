class Solution {
public:
    int m, n;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool backTrack(vector<vector<char>> &board, int i, int j, int idx, string word){
        if(idx == word.length())
            return true;
        if(i < 0 || j < 0 || i >= m || j>= n || board[i][j] == '&' || board[i][j] != word[idx])
            return false;
        char ch = board[i][j];
        board[i][j] = '&';

        for(int k = 0; k<4; k++){
            int newI = i + dir[k][0];
            int newJ = j + dir[k][1];
            if(backTrack(board, newI, newJ, idx+1, word))   
                return true;
        }
        board[i][j] = ch; // backtrack :- reverse the changes
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       m = board.size(); n = board[0].size();

       for(int i = 0; i< m ; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == word[0]){
                if(backTrack(board, i, j, 0, word))
                    return true;
            }
        }
       }
       return false; 
    }
};