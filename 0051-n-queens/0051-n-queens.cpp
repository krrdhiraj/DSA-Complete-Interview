class Solution {
public:
    vector<vector<string>> res;
    bool isSafe(vector<string>& board, int row, int col, int n){
        // check upward col
        for(int i = row-1; i >= 0; i--){
            if(board[i][col] == 'Q')
                return false;
        }
        // check left diagonal
        for(int i = row-1, j=col-1; j >= 0 && i >= 0; j--,i--){
            if(board[i][j] == 'Q')
                return false;
        }
        // check right diagonal
        for(int i = row-1, j=col+1; j < n && i >= 0; j++,i--){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void placeQueens(int n, int row, vector<string> &board){
        if(row >= n){
            res.push_back(board);
            return ;
        }
        for(int col = 0; col<n; col++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                placeQueens(n, row+1, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        placeQueens(n, 0, board);
        return res;

    }
};