class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;

        int l = 0, h = m*n-1;
        while(l <= h){
            int mid = (l + h)/2;
            int r = mid/n, c = mid%n;

            if(matrix[r][c] > target){
                h = mid-1;
            }else if(matrix[r][c] < target){
                l = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
}