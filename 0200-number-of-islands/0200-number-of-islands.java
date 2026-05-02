class Solution {
    int[][] direction = {{0,1},{1,0},{-1,0},{0,-1}};
    public void dfs(int i, int j, char[][] grid){
        if(i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == '0'){
            return ;
        }
        
        grid[i][j] = '0'; // already visited
        
        // now move further
        for(int[] dir : direction){
            dfs(i+dir[0], j + dir[1], grid);
        }
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