class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int t = n%k == 0? n/k : n/k + 1;
        String[] ans = new String[t];
        int i = 0, j = 0;
        while( i+k <= n){
            String temp = s.substring(i, i+k);
            ans[j++] = temp;
            i += k;
        }
        if(i < n){
            int sz = k - (n-i);
            
            String temp = s.substring(i);
            while(sz > 0){
                temp += fill;
                sz--;
            }
            ans[j] = temp;
        }
        return ans;
    }
}