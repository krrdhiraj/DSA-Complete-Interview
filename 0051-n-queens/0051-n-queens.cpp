class Solution {
public:
    vector<vector<string>> res;
    unordered_set<int> colSt;
    unordered_set<int> diagSt;
    unordered_set<int> antiDiagSt;
    
    void placeQueens(int n, int row, vector<string> &board){
        if(row >= n){
            res.push_back(board);
            return ;
        }
        for(int col = 0; col<n; col++){
            int diagonal = row + col;
            int antiDiag = row - col;
            if(colSt.find(col) != colSt.end() 
            || diagSt.find(diagonal) != diagSt.end() 
            || antiDiagSt.find(antiDiag) != antiDiagSt.end()){
                continue;
            }
            colSt.insert(col);
            diagSt.insert(diagonal);
            antiDiagSt.insert(antiDiag);
            board[row][col] = 'Q';
            placeQueens(n, row+1, board);
            board[row][col] = '.';
            colSt.erase(col);
            diagSt.erase(diagonal);
            antiDiagSt.erase(antiDiag);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        placeQueens(n, 0, board);
        return res;

    }
};