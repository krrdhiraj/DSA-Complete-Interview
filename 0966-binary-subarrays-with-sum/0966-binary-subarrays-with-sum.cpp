class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0;
        int n = nums.size();
        int sum = 0, cnt = 0;
        int cntZeros = 0;
        while(j < n){
            sum += nums[j];
            
            while(i < j && (nums[i] == 0 || sum > goal)){
                if(nums[i] == 0){
                    cntZeros += 1;
                }else{
                    cntZeros = 0;
                }
                sum -= nums[i];
                i++;
            }
            if(sum == goal){
                cnt += 1 + cntZeros;
            }
            j++;
        }
        return cnt ;
    }
}; 