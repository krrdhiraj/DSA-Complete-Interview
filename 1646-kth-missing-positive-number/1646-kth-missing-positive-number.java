class Solution {
    public int findKthPositive(int[] arr, int k) {
        int n = arr.length;

        int l = 1;
        int r = arr[n-1]+k;
        for(int val = l ; val <= r; val++){
            boolean found = false;
            for(int i = 0; i<n; i++){
                if(val == arr[i]){
                    found = true;
                    break;
                }
            }
             if(!found){
                    k--;
                }
                if(k == 0){
                    return val;
                }
           
        }
        return -1;
    }
}