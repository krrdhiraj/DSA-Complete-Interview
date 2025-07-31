class Solution {
    
    public int[] searchRange(int[]  arr, int target) {
       int n  = arr.length;
        int l = 0, r = n;
        while(l < r){
            int mid = (r+l)/2;
            if(arr[mid] == target){
                int first = mid, last= mid;
                while(first-1 >= 0 && arr[first] == arr[first-1]){
                    first--;
                }
                while(last+1 < n && arr[last] == arr[last+1]){
                    last++;
                }
                return new int[]{first, last};
            }
            if(arr[mid] < target){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return new int[]{-1,-1};


    }
}