class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int>& c, vector<int>& v,int sm, int t, int i ){
        if(i >= c.size()){
            if(sm == t)
                ans.push_back(v);
            return ;
        }
        if(sm <= t){
            sm += c[i];
            v.push_back(c[i]);
            helper(ans, c, v, sm, t, i);
            sm -= c[i];
        v.pop_back();
        }
        
        helper(ans, c, v, sm, t, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans, candidates, v, 0, target, 0);
        return ans;
    }
};