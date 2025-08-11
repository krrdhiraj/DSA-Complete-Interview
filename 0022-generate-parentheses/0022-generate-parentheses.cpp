class Solution {
public:
    vector<string> ans;
    bool isValid(string &str){
        int cnt = 0;
        for(char ch : str){
            if(ch == '('){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt < 0)
                return false;
        }
        return cnt == 0;
    }
    void solve(string& curr, int n){
        if(curr.length() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }

        // take open bracket
        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        // take close bracket
        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr, n);

        return ans;
    }
};