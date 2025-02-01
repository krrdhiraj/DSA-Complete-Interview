class Solution {
public:
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> preSm(n,0); // for storing the violating indices.
        for(int i = 1; i<n; i++){
           if((nums[i-1]%2) == (nums[i] % 2)){ // found violating index
                preSm[i] = preSm[i-1] + 1;
           }else{
                preSm[i] = preSm[i-1];
           }
        }
        int m = queries.size();
        vector<bool> ans(m,false);
        int i = 0;
        for(auto &v : queries){
            int s = v[0], e = v[1];
            if((preSm[e]-preSm[s]) == 0)
                ans[i] = true;
            i++;
        }
        return ans;
    }
};