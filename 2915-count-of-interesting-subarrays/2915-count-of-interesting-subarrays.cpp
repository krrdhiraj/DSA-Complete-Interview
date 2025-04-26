class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] % modulo == k){
                nums[i] = 1;
            }else{
                nums[i] = 0;
            }
        }
        long long res = 0;
        unordered_map<int,long long> mp; // store reminder => count
        mp[0] = 1;
        long long sum = 0;

        for(int i = 0; i<n; i++){   
            sum += nums[i]; 
            int r1 = sum % modulo;
            int r2 = (r1-k + modulo)% modulo;
            res += mp[r2];
            mp[r1]++;
        }
        return res;
    }
};