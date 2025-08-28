class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt  = 0;
        int n = s.length();
        vector<int> mp(3);
        int i = 0, j = 0;

        while(j < n){
            mp[s[j]-'a']++;
            while(mp[0] > 0 && mp[1] > 0 && mp[2] > 0){
                cnt += n-j;

                mp[s[i]-'a']--;
                i++;
            }
            j++;
        }
            
        return cnt;
    }
};