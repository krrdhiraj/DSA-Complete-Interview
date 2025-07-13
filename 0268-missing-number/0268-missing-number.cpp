class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        for(int i = 1; i<=n; i++){
            xor1 ^= i;
        }
        int xor2 = 0;
        for(int val : nums){
            xor2 ^= val;
        }
        return xor1^xor2;
    }
};