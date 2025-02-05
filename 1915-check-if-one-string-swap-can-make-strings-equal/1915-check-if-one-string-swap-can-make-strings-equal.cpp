class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int n = s1.length();
        int diff = 0;
        int firstIdx = 0;
        int secondIdx = 0;
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]){
                diff++;
                if(diff > 2)
                    return false;
                else if(diff == 1){
                    firstIdx = i;
                }else{
                    secondIdx = i;
                }
            }
        }
        if(s1[firstIdx] == s2[secondIdx] && s1[secondIdx] == s2[firstIdx]){
            return true;
        }
        return false;
    }
};