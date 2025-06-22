class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        int t = n%k == 0? n/k : n/k + 1;
        String[] ans = new String[t];
        int i = 0, j = 0;
        while( i < n){
            int end = Math.min(n, i+k);
            StringBuilder sb = new StringBuilder(s.substring(i, end));
            while(sb.length() < k){
                sb.append(fill);
            }
            ans[j++] = sb.toString();
            i += k;

        }
        
        return ans;
    }
}