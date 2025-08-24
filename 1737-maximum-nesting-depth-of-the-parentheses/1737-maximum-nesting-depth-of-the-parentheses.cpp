class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0, open = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                open++;
                ans = open > ans ? open : ans;
            }else if(s[i] == ')'){
                open--;
            }
        }
        return ans;
    }
};