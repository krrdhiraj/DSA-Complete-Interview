class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        int n = nums.size();

        priority_queue<pair<int,int>> pq; // {nums[i], i}

        for(int i = 0; i<n; i++){
            
            while(!pq.empty() && pq.top().second <= i-k){
                pq.pop();
            }
            
            // step 3 : push new element into dq
            pq.push({nums[i], i});

            // step - 4 : window pura hua ans nikalo
            if(i >= k-1){
                ans.push_back(nums[pq.top().second]);
            }
        }
        return ans;
    }
};