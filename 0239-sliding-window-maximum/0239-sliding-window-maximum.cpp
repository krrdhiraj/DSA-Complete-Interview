class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        int n = nums.size();

        deque<int> dq;

        for(int i = 0; i<n; i++){
            // new ke liye space banaoo
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //step-2 : chhote element ko remove krr do
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                 dq.pop_back();
            }
            // step 3 : push new element into dq
            dq.push_back(i);

            // step - 4 : window pura hua ans nikalo
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};