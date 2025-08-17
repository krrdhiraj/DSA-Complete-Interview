class Solution {
    public int find(int[] bloomDay, int day, int k){
        int bouqet = 0;
        int cnt = 0;
        for(int i = 0; i<bloomDay.length; i++){
            if(day >= bloomDay[i]){
                cnt++;
            }else{
                cnt = 0;
            }
            if(cnt == k){
                cnt = 0;
                    bouqet++;
            }
        }
        return bouqet;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if(n < (long)m * (long)k)
            return -1;
        int mx = Integer.MIN_VALUE;
        for(int val : bloomDay){
            mx = Math.max(mx, val);
        }
        int l = 1 , h = mx;
        while(l <= h){
            int mid = (l+h)/2;

            int noOfBouq = find(bloomDay, mid, k);

            if(noOfBouq < m){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return l;
    }
}