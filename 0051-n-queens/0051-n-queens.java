class Solution {
    List<List<String>> ans = new ArrayList<>();
    boolean isSafe(List<String> board, int row, int col, int n){
        // check upward
        for(int i = row-1; i>= 0; i--){
            if(board.get(i).charAt(col) == 'Q')
                return false;
        }
        // check right diagonal upward
        for(int i = row-1, j = col+1; i>= 0 && j < n; j++, i--){
            if(board.get(i).charAt(j) == 'Q')
                return false;
        }
        // check left diagonal upward
        for(int i = row-1, j = col-1; i>= 0 && j >= 0; j--, i--){
            if(board.get(i).charAt(j) == 'Q')
                return false;
        }
        return true;
    }
    public void placeQueens(List<String> board, int row, int n){
        if(row >= n){
            ans.add(new ArrayList<>(board));
            return ;
        }
        for(int col = 0; col < n; col++){
            if(isSafe(board, row, col, n)){
                StringBuilder sb = new StringBuilder(board.get(row));
                sb.setCharAt(col, 'Q');
                board.set(row, sb.toString());
                placeQueens(board, row+1, n);
                sb.setCharAt(col, '.');
                board.set(row, sb.toString());
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<String> board = new ArrayList<>();
       
        for(int i = 0; i<n; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j<n; j++){
                sb.append('.');
            }
            board.add(sb.toString());
        }
        placeQueens(board, 0, n);
        return ans;
    }
}