class Solution {
public:
    int slidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        int i = 0, j = 0;
        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int subarrWithKDiffEle = slidingWindow(nums,k);
        int subarrWithLessKDiff = slidingWindow(nums, k-1);

        return subarrWithKDiffEle - subarrWithLessKDiff;
    }
};