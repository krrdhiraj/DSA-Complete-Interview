class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m = nums1.size(), n = nums2.size();
        unordered_map<int,int> mp ;
        for(int val : nums1){
            mp[val]++;
        }
        for(int val : nums2){
            if(mp[val] >= 1){
                ans.push_back(val);
                mp[val] = 0;
            }
        }
        return ans;
    }
};