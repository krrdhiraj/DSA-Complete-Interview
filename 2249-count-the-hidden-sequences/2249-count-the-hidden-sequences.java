class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        int curr = 0;
        int maxVal = 0, minVal = 0;
      
        for(int d : differences){
            curr = curr + d;

            minVal = Math.min(minVal, curr);
            maxVal = Math.max(maxVal, curr);

            if((upper - lower) - (maxVal-minVal)+1 <= 0){
                return 0;
            }
        }
        return (upper - maxVal) - (lower-minVal)+1;
    }
}