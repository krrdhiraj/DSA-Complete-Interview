class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int j = n-1;
        while(j >= 0){
            char ch = s[n-1];
            for(int i = n-2; i>= 0; i--){
                s[i+1] = s[i];
            }
            s[0] = ch;
            if(s == goal)
                return true;
            j--;
        }
        return false;
    }
};