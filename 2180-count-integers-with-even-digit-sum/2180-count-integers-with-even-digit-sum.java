class Solution {
    public int countEven(int num) {
        int digSm = 0, temp = num;
        while(num >  0){
            digSm += num % 10;
            num /= 10;
        }

        return digSm % 2 == 0 ? temp/2 : (temp-1)/2;
    }
}