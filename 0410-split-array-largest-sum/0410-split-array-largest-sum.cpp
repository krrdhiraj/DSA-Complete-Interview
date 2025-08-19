class Solution {
public:
    int countSubArray(vector<int> &arr, int sm) {
        int subArr = 1;
        int currSm = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (currSm + arr[i] <= sm) {
                currSm += arr[i];
            }
            else {
                subArr++;
                currSm = arr[i];
            }
        }
        return subArr;
    }
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) 
            return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while(low <= high) {
            int midSm = (low + high)/2;

            if (countSubArray(arr, midSm) > k) {
                low = midSm+1;
            }else{
                high = midSm-1;
            }
        }
        return low;
    }
};