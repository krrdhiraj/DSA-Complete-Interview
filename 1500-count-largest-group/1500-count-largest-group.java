class Solution {
    int findDigitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    public int countLargestGroup(int n) {
        int[] mp = new int[40];
        int max = 0;
        for(int num = 1; num <= n; num++){
            int sum = findDigitSum(num);
            mp[sum]++;
            if(mp[sum] > max){
                max = mp[sum];
            }
        }
        int count = 0;
        for(int i = 0; i<40; i++){
            if(mp[i] == max){
                count++;
            }
        }
        return count;
    }
}