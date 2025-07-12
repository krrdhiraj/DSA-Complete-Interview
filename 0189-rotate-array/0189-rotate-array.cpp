class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2)
            return ;
        k %= n;
        while(k--){
            int temp = nums[0];
            for(int  i = n-1; i>0; i--){
                nums[(i+1)%n] = nums[i];
            }
            nums[1] = temp;
        }
    }
};