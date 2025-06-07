class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0; 
        unordered_map<int, int> mp;
        mp[0] = 1;
        int oddCnt = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 != 0){
                oddCnt++;
            }
            mp[oddCnt]++;
            ans += mp[oddCnt - k];
        }
        return ans;
    }
};