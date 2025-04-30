class Solution {
    int countDigit(int n){
        int cnt = 0;
        while(n > 0){
            cnt++;
            n /= 10;
        }
        return cnt;
    }
    public int findNumbers(int[] nums) {
        int ans = 0;
        for(int num : nums){
            int digits = countDigit(num);
            if(digits % 2 == 0)
                ans++;
        }
        return ans;

    }
}