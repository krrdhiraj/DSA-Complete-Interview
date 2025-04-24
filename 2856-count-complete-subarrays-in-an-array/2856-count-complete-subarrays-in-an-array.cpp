class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int distinctNum = st.size();

        int count = 0;
        int i = 0, j = 0;
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