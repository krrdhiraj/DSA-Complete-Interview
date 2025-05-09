class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int ans = 0;
        int n = arr.length;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j < n ; j++){
                 int diff1 = Math.abs(arr[i]-arr[j]);
                 if(diff1 > a)
                    continue;
                for(int k = j+1; k < n ; k++){
                    int diff2 = Math.abs(arr[j]-arr[k]);
                    int diff3 = Math.abs(arr[i] - arr[k]);
                    if(diff2 <= b && diff3 <= c){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}