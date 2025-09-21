class Solution {
    List<List<String>> ans = new ArrayList<>();
    public void placeQueens(List<String> board, int row, int n, HashSet<Integer> colSt, HashSet<Integer> diagSt, HashSet<Integer> antiDiagSt){
        if(row >= n){
            ans.add(new ArrayList<>(board));
            return ;
        }
        for(int col = 0; col < n; col++){
            int diagonal = row-col;
            int antiDiag = row+col;
            if(colSt.contains(col) || diagSt.contains(diagonal) || antiDiagSt.contains(antiDiag)){
                    continue;
            }
            colSt.add(col);
            diagSt.add(diagonal);
            antiDiagSt.add(antiDiag);
            StringBuilder sb = new StringBuilder(board.get(row));
            sb.setCharAt(col, 'Q');
            board.set(row, sb.toString());
            placeQueens(board, row+1, n, colSt, diagSt, antiDiagSt);
            sb.setCharAt(col, '.');
            board.set(row, sb.toString());
            colSt.remove(col);
            diagSt.remove(diagonal);
            antiDiagSt.remove(antiDiag);
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<String> board = new ArrayList<>();

        HashSet<Integer> colSt = new HashSet<>();
        HashSet<Integer> diagSt = new HashSet<>();
        HashSet<Integer> antiDiagSt = new HashSet<>();

       
        for(int i = 0; i<n; i++){
            StringBuilder sb = new StringBuilder();
            for(int j = 0; j<n; j++){
                sb.append('.');
            }
            board.add(sb.toString());
        }
        placeQueens(board, 0, n, colSt, diagSt, antiDiagSt);
        return ans;
    }
}