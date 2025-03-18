class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int pair = nums.size()/2;
        for(int i = 0; i< nums.size()-1; i+=2){
            if(nums[i] != nums[i+1])
                return false;
        }
        return true;
    }
};