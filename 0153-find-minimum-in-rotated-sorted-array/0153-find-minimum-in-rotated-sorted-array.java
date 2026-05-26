class Solution {
    public int findMin(int[] arr) {
        int n = arr.length;

        int l = 0, h = n-1;
        if(arr[l] < arr[h]){
            return arr[l];
        }

        while(l < h){
            int mid = (l+h)/2;
             if(arr[mid] > arr[h]){
                l = mid+1;
            }else{
                h = mid;
            }
        }
        return arr[h];
    }
}