class Solution {
public:
     vector<vector<int>> ans;
    void subseq(int k, int i, int sm, int n, vector<int>& temp){
        if(k == 0){
            if(sm == n){
                ans.push_back(temp);
            }
            return ;
        }
        if(i > 9)
            return ;
        sm += i;
        temp.push_back(i);
        subseq(k-1, i+1, sm, n, temp);
        sm -= i;
        temp.pop_back();
        subseq(k, i+1, sm, n, temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        vector<int> temp;
        subseq(k, 1, 0, n, temp);

        return ans;
    }
};