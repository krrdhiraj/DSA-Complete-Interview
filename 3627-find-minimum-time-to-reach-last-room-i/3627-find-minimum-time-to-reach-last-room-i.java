class Solution {
    private int[][] directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    class Cell implements Comparable<Cell>{
        int time;
        int row;
        int col;
        public Cell(int time, int row, int col){
            this.row = row;
            this.time = time;
            this.col = col;
        }
        @Override
        public int compareTo(Cell cell){
            return Integer.compare(this.time, cell.time);
        }
    }
    public int minTimeToReach(int[][] moveTime) {
        int m = moveTime.length;
        int n = moveTime[0].length;

        int[][] result = new int[m][n];
        for(int[] row : result){
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        result[0][0] = 0;

        PriorityQueue<Cell> pq = new PriorityQueue<>();
        pq.offer(new Cell(0,0,0));

        while(!pq.isEmpty()){
            Cell cell = pq.poll();
            int currRow = cell.row;
            int currCol = cell.col;
            int currTime = cell.time;

            if(currRow == m-1 && currCol == n-1){
                return currTime;
            }
            for(int[] dir : directions){
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                    int wait = Math.max(moveTime[newRow][newCol] - currTime, 0);
                    int arrivalTime = currTime + wait + 1;

                    if (result[newRow][newCol] > arrivalTime) {
                        result[newRow][newCol] = arrivalTime;
                        pq.offer(new Cell(arrivalTime, newRow, newCol));
                    }
                }
            }
        }
        return -1;
    }
}