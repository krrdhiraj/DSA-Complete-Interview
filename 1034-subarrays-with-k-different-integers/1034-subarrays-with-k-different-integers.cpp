class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        int i = 0, j = 0;
        int lastIdxOfI = 0;
        while(j < n){
            mp[nums[j]]++;

            // invalid subarray
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
                lastIdxOfI = i;
            }

            //shrink the window : jb tak nums[i] ki freq 1 nhi hoti means shrink till get min subarr length
            while(mp[nums[i]] > 1){
                mp[nums[i]]--;
                i++;
            }
            // calculate the no of subarr
            if(mp.size() == k){
                ans += (i - lastIdxOfI + 1);
            }
            j++;
        }
        return ans;
    }
};