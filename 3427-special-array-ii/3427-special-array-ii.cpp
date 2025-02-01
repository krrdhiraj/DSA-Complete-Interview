class Solution {
public:
    bool specialBinarySearch(int s, int e, vector<int> &vi){
        int l = 0, r = vi.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(s > vi[mid]){
                l = mid + 1;
            }else if(e < vi[mid]){
                r = mid - 1;
            }else{
                return true; // violating index mil gaya
            }
        }
        return false;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> violateIndx; // for storing the violating indices.
        
        for(int i = 1; i<n; i++){
           if((nums[i-1]%2) == (nums[i] % 2)){ // found violating index then store it.
                violateIndx.push_back(i);
           }
        }
        int m = queries.size();
        vector<bool> ans(m,false);
        int i = 0;
        for(auto &v : queries){
            int s = v[0], e = v[1];
            if(!specialBinarySearch(s+1,e, violateIndx))
                ans[i] = true;
            i++;
        }
        return ans;
    }
};