class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
       boolean sign = true;

       if(dividend >= 0 && divisor < 0) sign = false;
       if(dividend <= 0 && divisor >= 0) sign = false;

       long n = Math.abs(dividend), d = Math.abs(divisor);
       long ans = 0;
       while(d <= n){
       int cnt = 0;
        while(n >= (d << (cnt+1)))
            cnt++;
        ans += (1 << cnt);
        n = n - (d << cnt);
       }



       if(ans == (1<<31) && sign == true)
        return Integer.MAX_VALUE;
        if(ans == (1 << 31) && sign == false)
            return Integer.MIN_VALUE;
        if(sign == true)
            return (int)ans;
        return -(int)ans;
    }
}