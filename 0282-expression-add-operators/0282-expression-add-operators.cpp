class Solution {
public:
    vector<string> ans;
    
    void solve(string s, int idx, const string &res,long eval, long prev,  int target){
        if(idx == s.length()){
            if(eval == target)
                ans.push_back(res);
            return ;
        }
        string currStr ;
        long num = 0;
        for(int i = idx; i<s.length(); i++){
            if(i > idx && s[idx] == '0')
                break ;
           currStr += s[i];
           num = num*10 + s[i]-'0';
           if(idx == 0){
                solve(s, i+1, res+currStr, num, num, target);
           }else{
                solve(s, i+1, res + '+' + currStr, eval + num, num, target);
                solve(s, i+1, res + '-' + currStr, eval - num, -num, target);
                solve(s, i+1, res + '*' + currStr, (eval - prev) + (prev*num), prev*num, target);
           }
        }
    }
    vector<string> addOperators(string num, int target) {
        
        solve(num, 0, "", 0, 0,target);
        return ans;
    }
};