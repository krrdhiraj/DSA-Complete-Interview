class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p = INT_MIN;
        int pre = 1, suff = 1;
        for(int i = 0; i<n; i++){
           if(pre == 0) pre = 1;
           if(suff == 0) suff = 1;
           pre *= nums[i];
           suff *= nums[n-i-1];
           p = max(p, max(pre,suff));
        }
        return p;
    }
};