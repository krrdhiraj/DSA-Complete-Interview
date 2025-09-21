class Solution {
public:
vector<vector<int>> res;
    unordered_set<int> colSt;
    unordered_set<int> diagSt;
    unordered_set<int> antiDiagSt;
    
    void placeQueens(int n, int row, vector<string> &board, vector<int>& temp){
        if(row >= n){
            res.push_back(temp);
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
            temp.push_back(col+1);
            placeQueens(n, row+1, board, temp);
            board[row][col] = '.';
            colSt.erase(col);
            diagSt.erase(diagonal);
            temp.pop_back();
            antiDiagSt.erase(antiDiag);
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> temp;
        placeQueens(n, 0, board, temp);
        return res.size();
    }
};