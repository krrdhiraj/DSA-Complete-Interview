class Solution {
public:
    vector<vector<int>> ans;
    void recursion(vector<int> &can, int i, int sm,int target, vector<int>& temp){
        if(i >= can.size() ){
            if(sm == target){
                ans.push_back(temp);
            }
            return ;
        }
        
        if(sm < target){
            sm += can[i];
            temp.push_back(can[i]);
            recursion(can, i, sm, target, temp);
            sm -= can[i];
            temp.pop_back();
        }
        recursion(can, i+1, sm, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        recursion(candidates, 0, 0, target, temp);

        return ans;
    }
};