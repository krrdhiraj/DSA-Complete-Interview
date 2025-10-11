class Solution {
public:
    int mod = 1e9+7;
    int n ;
    int getNSR(vector<int>& arr, int i){
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[i])
                return j;
        }
        return n;
    }
    int getNSL(vector<int>& arr, int i){
        for(int j = i-1; j>= 0; j--){
            if(arr[j] <= arr[i])
                return j;
        }
        return -1;
    }
    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        long long sm = 0;
        for(int i = 0; i<n; i++){
            long long  NSR = getNSR(arr, i) - i;
            long long NSL = i - getNSL(arr, i);

            sm += (NSR*NSL*arr[i]) % mod;
            sm = sm % mod;
        }
        return sm;
    }
};