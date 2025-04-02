class Solution {
public:

    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long val = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(nums[j] >= nums[i])
                    continue;
                for(int k = j+1; k<n; k++){
                    long long tempVal =(long long)(nums[i]-nums[j])*nums[k];
                    if(tempVal > val){
                        val = tempVal;
                    }
                }
            }
        }
        return val;
    }
};