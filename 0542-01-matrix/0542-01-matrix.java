class Solution {
    public int[][] updateMatrix(int[][] mat) {
       int m = mat.length;
        int n = mat[0].length;

        Queue<int[]> que = new LinkedList<>();
        for(int i = 0; i<m ; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    que.offer(new int[]{i,j});
                }else{
                    mat[i][j] = -1;
                }
            }
        }

        int[][] dir = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        while(!que.isEmpty()){
                int[] curr = que.poll();
                int i = curr[0], j = curr[1];

                for(int[] d : dir){
                    int newI = i + d[0];
                    int newJ = j + d[1];
                    if(newI >= 0 && newI < m && newJ >=0 && newJ < n && mat[newI][newJ] == -1){
                        mat[newI][newJ] = mat[i][j]+1;
                        que.offer(new int[]{newI,newJ});
                    }
                }
        }
        return mat; 
    }
}