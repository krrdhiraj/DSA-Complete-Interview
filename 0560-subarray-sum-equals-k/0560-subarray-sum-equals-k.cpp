class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        int currSm = 0;
        for(int i = 0; i<n; i++){
            currSm += nums[i];
            if(mp.find(currSm - k) != mp.end()){
                ans += mp[currSm-k];
            }
            mp[currSm]++;

        }
        return ans;
    }
};