class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int missingNum = 0;
        for(int val : nums){
            missingNum ^= val;
        }
        return missingNum;
    }
};