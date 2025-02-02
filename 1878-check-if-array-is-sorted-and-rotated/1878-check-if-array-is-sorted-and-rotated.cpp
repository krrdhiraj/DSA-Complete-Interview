class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rotation = 0;
        for(int i = 0; i< n-1; i++){
            if(nums[i] > nums[i+1]){
                rotation++;
            }
        }
        if(nums[0] < nums[n-1]){
            rotation++;
        }
        return rotation > 1  ? false : true;
    }
};