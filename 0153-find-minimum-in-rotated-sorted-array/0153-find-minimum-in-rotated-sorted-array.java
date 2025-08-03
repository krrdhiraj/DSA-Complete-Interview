class Solution {
    public int findMin(int[] arr) {
        int n = arr.length;
 
        int low = 0, h = n-1;
        while(low < h){
            int mid = (low+h)/2;
            if(arr[mid] > arr[h]){
                low = mid+1;
            }else{
                h = mid;
            }
        }
        return arr[h];
    }
}