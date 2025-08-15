class Solution {
    public void solve(StringBuilder sb, int n, int open, int close, List<String> res){
        if(sb.length() == 2*n){
            res.add(sb.toString());
            return ;
        }
        if(open < n){
            sb.append('(');
            solve(sb, n, open+1, close, res);
            sb.deleteCharAt(sb.length()-1);
        }

        if(close < open){
            sb.append(')');
            solve(sb, n, open, close+1, res);
            sb.deleteCharAt(sb.length()-1);
        }
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        solve(sb, n, 0, 0, res);

        return res;
    }
}