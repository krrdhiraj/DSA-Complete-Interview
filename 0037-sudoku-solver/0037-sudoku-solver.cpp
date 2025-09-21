class Solution {
public:
    int n ;
    bool isSafe(vector<vector<char>>& board, int row, int col, char d){
        for(int i = 0; i<9; i++){
            // check row
            if(board[i][col] == d)
                return false;
            // check column
            if(board[row][i] == d)
                return false;
        }
        // check box
        int newRow = 3*(row/3);
        int newCol = 3*(col/3);
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[i+newRow][j+newCol] == d)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){

                    for(char d = '1'; d <= '9'; d++){

                        if(isSafe(board, row, col, d)){

                            board[row][col] = d;

                            if(solve(board) == true)
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};