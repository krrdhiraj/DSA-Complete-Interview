class Solution {
    public int searchInsert(int[] arr, int target) {
        int n  = arr.length;
        int l = 0, r = n;
        while(l < r){
            int mid = (r+l)/2;
            
            if(arr[mid] < target){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
}