class Solution {
    public void solve(int k, int n, int i, int sm , List<Integer> temp , List<List<Integer>> ans){
        if(k == 0){
            if(n == sm){
                ans.add(new ArrayList<>(temp));
            }
            return ;
        }
        if(i > 9)
            return;
        sm += i;
        temp.add(i);
        solve(k-1, n, i+1, sm, temp, ans);
        sm -= i;
        temp.remove(temp.size()-1);
        solve(k, n, i+1, sm, temp, ans);
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        solve(k, n, 1, 0, temp, ans);
        return ans;
    }
}