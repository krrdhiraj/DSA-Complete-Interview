class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int val : arr){
            mp[val]++;
        }
        int ans = -1;
        for(auto &it : mp){
            if(it.first == it.second){
                ans = max(ans, it.first);
            }
        }
        return ans;
    }
};