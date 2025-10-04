class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for(int j = 2*n-1; j>= 0; j--){
            while(!st.empty() && st.top() <= nums[j%n]){
                st.pop();
            }
            if(j < n){
                if(st.empty()){
                    ans[j] = -1;
                }else{
                    ans[j] = st.top();
                }
            }
            st.push(nums[j % n]);
        }
       
        return ans;
    }
};