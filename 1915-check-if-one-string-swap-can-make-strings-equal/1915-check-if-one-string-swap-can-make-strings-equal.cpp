class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        int n = s1.length();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = n-1; j > i; j--){
                swap(s1[i], s1[j]);
                if(s1 == s2)
                    return true;
                swap(s1[j], s1[i]);
            }
            if(s1 == s2)
                return true;
        }
        return false;
    }
};