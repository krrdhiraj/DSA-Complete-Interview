class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0; 
        unordered_map<int, int> mp;
        int oddCnt = 0;
        mp[oddCnt] = 1;

        for(int i = 0; i<n; i++){
            oddCnt += nums[i] % 2;
            if(mp.count(oddCnt-k)){
                ans += mp[oddCnt - k];
            }
           mp[oddCnt]++;
        }
        return ans;
    }
};