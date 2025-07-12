class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int cntZero = 0;
        for(int val : nums){
            if(val == 0)
                cntZero++;
        }
        while(cntZero--){
            for(int i = 0; i<n-1; i++){
                if(nums[i] == 0 && nums[i+1] != 0){
                    swap(nums[i+1], nums[i]);
                }
            }
        }
    }
};