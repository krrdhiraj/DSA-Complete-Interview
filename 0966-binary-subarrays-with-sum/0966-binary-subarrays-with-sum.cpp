class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0, cnt = 0;
        unordered_map<int,int> mp;
        mp[sum] = 1;
        for(int i = 0; i<n; i++){
            sum += nums[i];

            int remaining = sum - goal;
            if(mp.find(remaining) != mp.end())
                cnt += mp[remaining];
            mp[sum]++;
        }
        return cnt ;
    }
}; 