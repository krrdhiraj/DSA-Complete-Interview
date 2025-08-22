class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;

        for(int i = 0; i<m; i++){
            int l = 0, h = n-1;
            while(l <= h){
                int mid = (l+h)/2;
                if(matrix[i][mid]== target){
                    return true;
                }else if(matrix[i][mid] > target){
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return false;
    }
}