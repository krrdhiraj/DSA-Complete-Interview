class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            int mp[256] = {0};

            for(int j = i; j<n; j++){
                if(mp[s[j]] == 1){
                    break;
                }
                ans = max(ans, j-i+1);
                mp[s[j]] = 1;
            }
        }
        return ans;
    }
};