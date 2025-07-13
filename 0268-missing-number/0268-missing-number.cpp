class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sm = (n*(n+1))/2;
        int sm2 = 0;
        for(int val : nums){
            sm2 += val;
        }
        return sm - sm2;
    }
};