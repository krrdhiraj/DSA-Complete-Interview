class Solution {
    public int beautySum(String s) {
        int n = s.length();

        int ans = 0;

        for(int i = 0; i<n; i++){
            int[] freq = new int[26];
            for(int j = i; j < n ;j++){
                freq[s.charAt(j)-'a']++;
                int mxFreq = 0, mnFreq = Integer.MAX_VALUE;
                for(int k = 0; k<26; k++){
                    mxFreq = Math.max(mxFreq, freq[k]);
                    if(freq[k] != 0)
                        mnFreq = Math.min(mnFreq, freq[k]);
                }
                ans += mxFreq - mnFreq;
            }
        }
        return ans;
    }
}