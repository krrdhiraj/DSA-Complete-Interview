class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0, mxlen = 0, cnt = 0;
        unordered_map<char, int> mp;
        while(j < n){
            mp[s[j]]++;
           cnt++;
            while(mp[s[j]] > 1){
                mxlen = max(mxlen, cnt-1);
                mp[s[i]]--;
                cnt = j-i;
                i++;
            }
            j++;
        }
        return max(cnt,mxlen);
    }
};