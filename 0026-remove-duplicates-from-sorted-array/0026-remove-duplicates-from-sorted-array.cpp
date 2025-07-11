class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0, n = nums.size();
        int i = 0;
        vector<int> expected;

        while(i < n){
            while(i + 1 < n && nums[i] == nums[i+1]){
                i++;
            }
            expected.push_back(nums[i]);
            i++;
        }
        k = expected.size();
        nums.clear();
        for(int i = 0; i<k ; i++){
            nums.push_back(expected[i]);
        }
        return k;
    }
};