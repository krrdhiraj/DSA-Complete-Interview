class Solution {
public:
    int cnt = 0;
    void merge(vector<int>& nums, int low, int mid, int high){
        int left = low;
        int right = mid+1;
        vector<int> temp;
        while(left <= mid && right <= high){
            
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(nums[right++]);
        }
        for(int i = low; i<= high; i++){
            nums[i] = temp[i-low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low >= high){
            return ;
        }
        int mid = (low+high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        int left = low, right = mid+1;
        for(; left <= mid; left++){
            while(right <= high && (nums[left] > (long)2*nums[right])){
                    right++;
            }
            cnt += (right-mid-1);
        }
        merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0, n-1);
        return cnt;
    }
};