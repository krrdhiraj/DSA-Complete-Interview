class Solution {
    public void dfs(int i, int j, char[][] grid){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0'){
            return ;
        }
        
        grid[i][j] = '0'; // already visited
        
        // now move further
        dfs(i+1, j, grid); // down
        dfs(i, j+1, grid); // right
        dfs(i, j-1, grid); // up
        dfs(i-1, j, grid); // left
    }
    public int numIslands(char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int noOfIsland = 0;
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '1'){
                    // found 1st island count it
                    noOfIsland++;
                    // find 1st island
                    dfs(i, j, grid);
                }
            }
        }

        return noOfIsland;
    }
}