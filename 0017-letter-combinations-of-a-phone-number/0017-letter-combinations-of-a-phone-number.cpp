class Solution {
public:
    unordered_map<int,string> mp{{2,"abc"}, {3,"def"}, {4, "ghi"}, {5, "jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
    void solve(string& digits, int idx, string& temp, vector<string> &ans){
        if(idx >= digits.length()){
            ans.push_back(temp);
            return ;
        }
        string s = mp[digits[idx]-'0'];
        for(int i = 0 ; i< s.length(); i++){
            temp.push_back(s[i]);
            solve(digits, idx+1, temp, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return {};
        vector<string> ans;
        string temp;


        solve(digits, 0, temp, ans);
        return ans;
    }
};