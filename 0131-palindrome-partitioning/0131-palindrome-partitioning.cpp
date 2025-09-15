class Solution {
public:
    bool isPalindrome(string s){
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    void solve(string &s, int idx, vector<string> temp ,vector<vector<string>> &ans){
        if(idx == s.length()){
           ans.push_back(temp);
            return;
        }
        for(int i = idx; i<s.length(); i++){
            string str = s.substr(idx, i-idx+1);
            if(isPalindrome(str)){
                temp.push_back(str);
                solve(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
       
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};