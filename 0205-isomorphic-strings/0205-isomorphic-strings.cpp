class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length(), m = t.length();
        if(m != n)
            return false;
        int mp1[200];
        int mp2[200];
        for(int i = 0; i<n; i++){
            if(mp1[s[i]] != mp2[t[i]])
                return false;
            mp1[s[i]] = i+1;
            mp2[t[i]] = i+1;
        }
        return true;
    }
};