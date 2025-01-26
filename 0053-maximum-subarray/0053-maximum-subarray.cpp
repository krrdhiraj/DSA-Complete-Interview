class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxSm = INT_MIN;
        int n = nums.size();
        int currSm = 0;
        for(int i = 0; i<n; i++){
           currSm += nums[i];
           mxSm = max(currSm, mxSm);
           if(currSm < 0)
                currSm = 0;
        }
        return mxSm;
    }
};