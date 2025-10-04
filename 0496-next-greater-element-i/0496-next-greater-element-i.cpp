class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        int n = nums2.size();
        stack<int> st;
        for(int j = n-1; j>= 0; j--){
            while(!st.empty() && st.top() <= nums2[j]){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[j]] = -1;
            }else{
                mp[nums2[j]] = st.top();
            }
            st.push(nums2[j]);
        }
        vector<int> ans;
        for(int val : nums1){
            ans.push_back(mp[val]);
        }
        return ans;
    }
};