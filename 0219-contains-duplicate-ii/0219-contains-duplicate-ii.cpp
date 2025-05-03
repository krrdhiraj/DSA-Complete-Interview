class Solution {
public:
    // Brute force approach TC{O(n^2)}
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it : mp){
            vector<int> v = it.second;
            for(int i = 0; i<v.size()-1; i++){
                if(abs(v[i]-v[i+1]) <= k)
                    return true;
            }
        }
        return false;
    }
};