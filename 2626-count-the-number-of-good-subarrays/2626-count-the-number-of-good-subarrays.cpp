class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long pairs = 0;
        long long ans = 0;
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while(pairs >= k){
                ans += (n-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};