class Solution {
    int mod = (int)1e9+7;
    private long findPower(long a, long b){
        if(b == 0)
            return 1;
        long half = findPower(a, b/2);
        long ans = (half * half) % mod;
        if(b%2 == 1){
            ans = (ans*a)%mod;
        }
        return ans;
    }
    public int countGoodNumbers(long n) {
        long evenInd = (n+1)/2;
        long oddIndx = n/2;
        long ans = (findPower(5,evenInd) * findPower(4 , oddIndx)) % mod;
        return (int)ans;
    }
}