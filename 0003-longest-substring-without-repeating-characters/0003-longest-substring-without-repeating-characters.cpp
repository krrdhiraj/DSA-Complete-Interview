class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i = 0, j = 0;
        unordered_map<char,int> mp;
        int ans = 0;
        while(j < n){
            mp[s[j]]++;

            if(j-i+1 == mp.size()){
                ans = ans > mp.size() ? ans : mp.size();
            }
            else if(mp.size() < j-i+1){
                while( mp.size() < j-i+1){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};