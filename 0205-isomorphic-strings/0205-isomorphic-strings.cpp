class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.length(), n = t.length();

        if(m != n)
            return false;

        unordered_map<char,char> mp;
        for(int i = 0; i<n; i++){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] != t[i]){
                return false;
            }
            mp[s[i]] = t[i];
        }
        return true;
    }
};