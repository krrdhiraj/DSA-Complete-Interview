class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int maxEle = *max_element(begin(nums), end(nums));
        vector<int> maxEleIndices;

        for(int i= 0; i<n; i++){
            if(nums[i] == maxEle){
                maxEleIndices.push_back(i);
            }
            int sz = maxEleIndices.size();
            if(sz >= k){
                int lastIdxOfMax = maxEleIndices[sz-k];
                ans += lastIdxOfMax+1;
            }
        }
        return ans;
       
        return ans;
    }
};