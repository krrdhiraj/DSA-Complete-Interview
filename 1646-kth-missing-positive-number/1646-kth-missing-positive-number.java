class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;
        int m = n+k;
        int cnt  = 0;
        for(int i = 1; i<= m; i++){
            boolean found = false;
            for(int j = 0; j<n; j++){
                if(arr[j] == i){
                    found = true;
                }
            }
            if(!found){
                cnt++;
            }
            if(cnt == k){
                return i;
            }
        }
        return 0;
    }
}