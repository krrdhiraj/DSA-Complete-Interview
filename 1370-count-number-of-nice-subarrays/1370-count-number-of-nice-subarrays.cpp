class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0; 
        int previousCnt = 0;
        int odd = 0;
        int i = 0, j = 0;
        
        while(j < n){
            if(nums[j] % 2 != 0){
                odd += 1;
                previousCnt = 0;
            }

            while(i < n && odd== k){
                previousCnt++;
                if(nums[i] % 2 != 0){
                    odd--;
                }
                i++;
            }
            ans += previousCnt;
            j++;
        }
        return ans;
    }
};