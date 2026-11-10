class Solution {
public:
    int digitSm(int n){
        int digSm = 0;
        while(n > 0){
            digSm += n % 10;
            n = n/10;
        }
        return digSm;
    }
    int countEven(int num) {
        int cnt = 0;
        for(int n = 2; n<= num; n++){
            int digSm = digitSm(n);
            if(digSm % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};