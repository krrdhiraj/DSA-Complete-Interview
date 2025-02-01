class Solution {
public:
    bool specialArray(vector<int> &nums, int &s, int &e){
        for(int i = s; i<=e-1; i++){
            if((nums[i] % 2) == (nums[i+1] % 2))
                return false;
        }
        return true;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> preSm(n,0);
        for(int i = 1; i<n; i++){
           if((nums[i-1]%2) == (nums[i] % 2)){
                preSm[i] = preSm[i-1] + 1;
           }else{
                preSm[i] = preSm[i-1];
           }
        }
        vector<bool> ans;
        for(auto &v : queries){
            int s = v[0], e = v[1];
            ans.push_back((preSm[e]-preSm[s]) == 0 ? true : false);
        }
        return ans;
    }
};