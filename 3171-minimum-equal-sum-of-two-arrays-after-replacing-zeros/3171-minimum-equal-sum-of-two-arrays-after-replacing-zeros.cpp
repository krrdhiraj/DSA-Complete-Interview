class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        long long sm1 = 0, sm2 = 0;
        int zero1 = 0, zero2 = 0;

        for(int num : nums1){
            sm1 += num;
            if(num == 0){
                zero1++;
            }
        }
        for(int num : nums2){
            sm2 += num;
            if(num == 0){
                zero2++;
            }
        }
        if((zero1 == 0 && sm1 < sm2 + zero2) || (zero2 == 0 && sm2 < sm1+zero1)){
            return -1;
        } 
        return max(zero1+sm1, zero2 + sm2);
    }
};