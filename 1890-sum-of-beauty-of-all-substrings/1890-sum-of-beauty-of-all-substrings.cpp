class Solution {
public:
    int beautySum(string s) {
        int n = s.length();

        int ans = 0;

        for(int i = 0; i<n; i++){
            int freq[26]= {0};
            for(int j = i; j < n ;j++){
                freq[s[j]-'a']++;
                int mxFreq = 0, mnFreq = INT_MAX;
                for(int k = 0; k<26; k++){
                    mxFreq = max(mxFreq, freq[k]);
                    if(freq[k] != 0)
                        mnFreq = min(mnFreq, freq[k]);
                }
                ans += mxFreq - mnFreq;
            }
        }
        return ans;
    }
};