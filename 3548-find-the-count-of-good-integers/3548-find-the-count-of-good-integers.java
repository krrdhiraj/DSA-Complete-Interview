class Solution {
    public long countGoodIntegers(int n, int k) {
        Set<String> st = new HashSet<>();

        int d = (n+1)/2;

        int start = (int)Math.pow(10, d-1);
        int end = (int)Math.pow(10, d)-1;

        for(int num = start; num <= end; num++){
            String left = Integer.toString(num);
            String full ;

            if(n % 2 == 0){
                StringBuilder right = new StringBuilder(left).reverse();
                full = left + right.toString();
            }else{
                StringBuilder right = new StringBuilder(left.substring(0,d-1)).reverse();
                full = left + right.toString();
            }

            long number = Long.parseLong(full);
            if(number % k != 0){
                continue;
            }
            char[] chars = full.toCharArray();
            Arrays.sort(chars);
            st.add(new String(chars));
        }
        // calculating factorial
        long[] fact = new long[11];
        fact[0] = 1;
        for(int i = 1; i<11; i++){
            fact[i] = fact[i-1] * i;
        }

        long ans = 0;
        // now find the permutation of every palindromic string
        for(String s : st){
            int[] count = new int[10];
            for(char ch : s.toCharArray()){
                count[ch-'0']++;
            }

            int totalDigits = s.length();
            int zeroDigits = count[0];
            int nonZeroDigits = totalDigits - zeroDigits;

            long permut = (nonZeroDigits * fact[totalDigits - 1]);

            for(int i = 0; i<10; i++){
                permut /= fact[count[i]];
            }
            ans += permut;
        }
        return ans;
    }
}