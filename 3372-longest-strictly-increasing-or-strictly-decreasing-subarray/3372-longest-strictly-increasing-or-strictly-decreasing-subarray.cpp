class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int j = i+1; 
            int incr = 1;
            while(j < n && nums[j-1] < nums[j]){
                incr++;
                j++;
            }
            j = i+1;
            int decr = 1;
            while(j < n && nums[j-1] > nums[j]){
                decr++;
                j++;
            }
            len = max(max(incr,decr), len);
        }
        return len;
    }
};