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
        for(int i = 0; i<n; i++){
            mp.clear();
            for(int j = i; j<n; j++){
                mp[nums[j]]++;
                if(mp.size() == distinctNum){
                    count++;
                }
            }
        }
        return count;
    }
};