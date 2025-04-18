class Solution {
public:
    string countAndSay(int n) {
        vector<string> ans(n);
        ans[0] = "1";

        for(int i = 1; i<n; i++){
            string s = ans[i-1];
            int cnt = 1;
            string temp = "";
            for(int j = 1; j<s.length(); j++){
                if(s[j] == s[j-1]){
                    cnt++;
                }else{
                    temp += to_string(cnt) + s[j-1];
                    cnt = 1;
                }
            }
            temp += to_string(cnt) + s[s.length()-1];
            ans[i] = temp;
        }
        return ans[n-1];
    }
};