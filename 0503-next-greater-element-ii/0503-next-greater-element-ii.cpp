class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for(int j = n-1; j>= 0; j--){
            while(!st.empty() && st.top() <= nums[j]){
                st.pop();
            }
            if(st.empty()){
                ans[j] = -1;
            }else{
                ans[j] = st.top();
            }
            st.push(nums[j]);
        }
        for(int j = n-1; j> 0; j--){
            while(!st.empty() && st.top() <= nums[j]){
                st.pop();
            }
            if(st.empty()){
                ans[j] = -1;
            }else{
                ans[j] = st.top();
            }
            st.push(nums[j]);
        }
        // ans[n-1] = st.size() == 0 ? -1 : st.top();
        return ans;
    }
};