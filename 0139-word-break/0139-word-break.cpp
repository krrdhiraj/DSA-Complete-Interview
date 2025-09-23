class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    bool solve(string s, vector<string>& word, int idx){
       
        if(idx >= s.length()){
            return true;
        }
        if(dp[idx] != -1)
            return dp[idx];
            
        if(st.find(s) != st.end()){
            return true;
        }
        for(int len = 1; len < s.length(); len++){
            string temp = s.substr(idx, len);
            if(st.find(temp) != st.end() && solve(s, word, idx+len) ){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string word : wordDict){
            st.insert(word);
        }
        memset(dp, -1, sizeof(dp));
        return solve(s, wordDict, 0);
    }
};