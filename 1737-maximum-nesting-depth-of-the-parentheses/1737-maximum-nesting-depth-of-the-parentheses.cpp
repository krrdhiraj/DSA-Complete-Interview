class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int ans = 0;
        stack<char> st;
        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                st.push(s[i]);
                ans = st.size() > ans ? st.size() : ans;
            }else if(s[i] == ')'){
                st.pop();
            }
        }
        return ans;
    }
};