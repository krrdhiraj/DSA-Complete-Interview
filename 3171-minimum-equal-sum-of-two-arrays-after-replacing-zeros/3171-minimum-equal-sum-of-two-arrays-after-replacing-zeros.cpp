class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        long long sm1 = 0, sm2 = 0;
        int zero1 = 0, zero2 = 0;

        for(int num : nums1){
            sm1 += num == 0? 1 : num;
            zero1 += num == 0 ? 1 : 0;
        }
        for(int num : nums2){
            sm2 += num == 0 ? 1 : num;
            zero2 += num == 0 ? 1 : 0;
        }
        if((zero1 == 0 && sm1 < sm2) || (zero2 == 0 && sm2 < sm1)){
            return -1;
        } 
        return max(sm1, sm2);
    }
};