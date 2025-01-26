class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int p = nums[0];
        for(int i = 0; i<n; i++){
            int product = nums[i];
            p = max(product,p);
            for(int j = i+1; j < n; j++){
                product *= nums[j];
                if(p < product){
                    p = product;
                }
            }
        }
        return p;
    }
};