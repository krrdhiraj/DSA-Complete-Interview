class Solution {
public:
    int findDigitSum(int n){
        int sm = 0;
        while(n){
            sm += n%10;
            n = n/10;
        }
        return sm;
    }
    int countLargestGroup(int n) {
        int mp[37];
        int max = 0;
        for(int num = 1; num <= n; num++){
            int sum = findDigitSum(num);
            mp[sum]++;
            if(mp[sum] > max){
                max = mp[sum];
            }
        }
        int count = 0;
        for(int i = 0; i<37; i++){
            if(mp[i] == max){
                count++;
            }
        }
        return count;
    }
};