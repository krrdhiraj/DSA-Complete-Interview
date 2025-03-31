class Solution {
    public long putMarbles(int[] weights, int k) {
         int n = weights.length-1;
        
        int[] pairSum = new int[n];
        for(int i = 0; i<n; i++){
            pairSum[i] = weights[i]+weights[i+1];
        }
        Arrays.sort(pairSum);
        long maxSm = 0, minSm = 0;
        int i = 0, j = n-1;

        while(k-- > 1){
            minSm += pairSum[i++];
            maxSm += pairSum[j--];
        }

        return (maxSm - minSm);
    }
}