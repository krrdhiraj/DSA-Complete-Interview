class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long cntOfBadPairs = 0;
        for(int i = 0; i<n; i++){
            nums[i] = nums[i]-i;
        }
        unordered_map<int,int> mp;
       
        for(int j = 0; j<n; j++){
            int goodPair = mp[nums[j]];
            cntOfBadPairs += j - goodPair;
            mp[nums[j]]++;
        }
        return cntOfBadPairs;
    }
};