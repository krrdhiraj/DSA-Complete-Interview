class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i<= n; i++){
            if(nums[i%n] == target){
                return i;
            }
        }
        return -1;
    }
};