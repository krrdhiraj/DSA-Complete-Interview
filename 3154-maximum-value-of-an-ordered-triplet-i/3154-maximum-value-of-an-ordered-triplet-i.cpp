class Solution {
public:

    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], nums[i-1]);
        }
        for(int j = n-2; j>=0; j--){
            rightMax[j] = max(rightMax[j+1], nums[j+1]);
        }

        // calculate the max triplets
        for(int i = 0; i<n ; i++){
            ans = max(ans, (long long)(leftMax[i]-nums[i])*rightMax[i]);
        }
        return ans;
    }
};