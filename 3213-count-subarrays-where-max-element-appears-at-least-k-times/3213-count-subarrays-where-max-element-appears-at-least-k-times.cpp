class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0;
        int maxEle = *max_element(begin(nums), end(nums));
        
        int cntOfMax = 0;
        while(j < n){
            if(nums[j] == maxEle){
                cntOfMax++;
            }
            while(cntOfMax == k){
                ans += (n-j);
                if(nums[i] == maxEle ){
                    cntOfMax--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};