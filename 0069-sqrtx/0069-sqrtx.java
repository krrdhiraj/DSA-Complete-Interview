class Solution {
    public int mySqrt(int x) {
      int low = 0, high = x;
    
        while(low * low <= x){
            low = low+1;
        }
        return (int)low-1;
     
    }
}