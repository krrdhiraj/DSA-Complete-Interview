class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums){
            mp[num]++;
        }
        int distinctNum = mp.size();

        int count = 0;
        int i = 0, j = 0;
        mp.clear();
        while(j < n){
            mp[nums[j]]++;

            while(mp.size() == distinctNum ){
                count += (n-j);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return count;
    }
};