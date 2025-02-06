class Solution {
public:
//  Best Approach(TC - {O(n^2) + O(nlong(n))})
// SC - {O(n)}
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple = 0;
        sort(begin(nums), end(nums));
        unordered_map<int,int> mp;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int p = nums[i]*nums[j];
                mp[p]++;
            }
        }
        // now count the tuples
        for(auto &it : mp){
            int prod = it.first;
            int freq = it.second;
            tuple += (freq*(freq-1))/2;
        }
        return tuple*8;
    }
};