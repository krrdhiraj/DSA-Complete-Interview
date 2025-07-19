class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = 0;
        for(int i = n-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                pivot = i;
                break;
            }
        }
        if(pivot != 0){
            int swapIdx = pivot;
            for(int j = n-1; j >= pivot; j--){
                if(nums[j] > nums[pivot-1]){
                    swapIdx = j;
                    break;
                }
            }
            swap(nums[swapIdx], nums[pivot-1]);
        }
        reverse(nums.begin()+pivot, nums.end());
    }
};