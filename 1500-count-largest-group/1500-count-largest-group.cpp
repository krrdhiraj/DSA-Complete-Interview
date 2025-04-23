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
        int maxSize = 0;
        int count = 0;
        unordered_map<int,int> mp;
        for(int num = 1; num <= n; num++){
            int sm = findDigitSum(num);
            mp[sm]++;
            if(mp[sm] == maxSize){
                count++;
            }else if(mp[sm] > maxSize){
                maxSize = mp[sm];
                count = 1;
            }
        }
        return count;
    }
};