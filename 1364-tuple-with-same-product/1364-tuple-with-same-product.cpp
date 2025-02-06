class Solution {
public:
//  Better Approach(TC - {O(n^3) + O(nlong(n))})
// SC - {O(n)}
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple = 0;
        sort(begin(nums), end(nums));
        for(int i = 0; i<n; i++){
            for(int j = n-1; j > i; j--){
                int prdct = nums[i] * nums[j];
                unordered_set<int> st;
                for(int k = i+1; k < j; k++){
                    if(prdct % nums[k] == 0){
                        int d = prdct / nums[k];
                        if(st.count(d)){
                            tuple++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return tuple*8;
    }
};