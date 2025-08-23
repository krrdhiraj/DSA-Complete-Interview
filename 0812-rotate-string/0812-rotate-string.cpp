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
            rotate(s.begin(), s.begin()+1, s.end());
            i++;
        }
        return false;
    }
};