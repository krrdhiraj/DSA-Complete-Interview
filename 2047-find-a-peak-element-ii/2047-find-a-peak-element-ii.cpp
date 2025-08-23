class Solution {
public:
    int findMax(vector<vector<int>> &mat,int n, int col){
        int idx = -1;
        int mxVal = -1;

        for(int i = 0; i<n; i++){
            if(mat[i][col] > mxVal){
                mxVal = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, h = n-1;
        while(l <= h){
            int mid = (l+h)/2;

            int rowMaxIdx = findMax(mat, m, mid);
            int left = mid-1 >= 0 ? mat[rowMaxIdx][mid-1] : -1;
            int right = mid+1 < n ? mat[rowMaxIdx][mid+1] : -1;

            if(mat[rowMaxIdx][mid] > left && mat[rowMaxIdx][mid] > right){
                return {rowMaxIdx,mid};
            }else if(mat[rowMaxIdx][mid] < left){
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return {-1,-1};
    }
};