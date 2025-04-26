class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        vector<int> vec(n,0);

        for(int i = 0; i<n; i++){
            if(nums[i] % modulo == k){
                vec[i] = 1;
            }
        }
        long long res = 0;
        unordered_map<int,long long> mp;
        mp[0] = 1;
        long long sum = 0;
        for(int i = 0; i<n; i++){   
            sum += vec[i]; 
            int r1 = sum % modulo;
            int r2 = (r1-k + modulo)% modulo;
            res += mp[r2];
            mp[r1]++;
        }
        return res;
    }
};