class Solution {
public:
    void recursion(vector<int>& candidates, int i , int sm, int target, vector<vector<int>> &ans, vector<int>& temp){
         if(sm > target){
            return ;
         }
         if(sm == target){
            ans.push_back(temp);
            return ;
        }
           
       
        for(int idx = i; idx<candidates.size(); idx++){
            if(idx > i && candidates[idx] == candidates[idx-1])
                continue;

            temp.push_back(candidates[idx]); // do
            recursion(candidates, idx+1, sm+candidates[idx], target, ans, temp);
            temp.pop_back(); // undo
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        recursion(candidates, 0, 0, target, ans, temp);

        return ans;
    }
};