class Solution {
    public int minEatingSpeed(int[] piles, int h) {
         int n = piles.length;
        int mx = Integer.MIN_VALUE;
        for(int val : piles){
            mx = Math.max(mx, val);
        }
        int l = 1; 
        int r = mx;
        while(l <= r){
            int mid = (r+l)/2;
            int sm = 0;
            for(int i = 0; i<n; i++){
                sm += Math.ceil((double)piles[i]/ (double)mid);
            }
            if(sm <= h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
}