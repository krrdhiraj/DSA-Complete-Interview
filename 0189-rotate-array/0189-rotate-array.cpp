class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return ;
        k = k % n;
        while(k--){
            int temp = nums[n-1];
            for(int  i = n-2; i>=0; i--){
                nums[i+1] = nums[i];
            }
            nums[0] = temp;
        }
    }
};