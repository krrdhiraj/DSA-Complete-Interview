class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(m != n)  return false;
        int i  = 0;
        while(i < n){
            if(s == goal)
                return true;
            char ch = s[n-1];
            s.pop_back();
            s.insert(s.begin(), ch);
            i++;
        }
        return false;
    }
};