class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int minKIndx = -1, maxKIndx = -1, culpritIdx = -1;

        for(int i = 0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culpritIdx = i;
            }

            if(nums[i] == minK){
                minKIndx = i;
            }
            if(nums[i] == maxK){
                maxKIndx = i;
            }
            int smallIndx = min(minKIndx, maxKIndx);
            int temp = smallIndx - culpritIdx;
            ans += temp <= 0 ? 0 : temp;
        }
        return ans;
    }
};