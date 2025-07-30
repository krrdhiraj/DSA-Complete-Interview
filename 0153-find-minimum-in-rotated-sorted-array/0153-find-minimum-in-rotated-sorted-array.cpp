class Solution {
public:
    int findMin(vector<int>& nums) {
        int minm = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<= n; i++){
           minm = min(minm, nums[i%n]);
        }
        return minm;
    }
};