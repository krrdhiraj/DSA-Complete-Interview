class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n= nums.size();
        int zeroIdx = -1;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0)
            {
                zeroIdx = i;
                break;
            }
        }
        for(int i = zeroIdx+1; i<n; i++){
            if(nums[i] != 0 && zeroIdx != -1){
                swap(nums[i], nums[zeroIdx]);
                zeroIdx++;
            }
        }
        
    }
};