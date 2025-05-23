class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long cntOfBadPairs = 0;
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]-i;
        }
        unordered_map<int,int> mp;
        mp[nums[0]] = 1;
        for(int j = 1; j<n; j++){
            cntOfBadPairs += j - mp[nums[j]];
            mp[nums[j]]++;
        }
        return cntOfBadPairs;
    }
};