class Solution {
   
    public int countPrimes(int n) {
        int count = 0;
        int[] primes = new int[n+1];

        // O(N)
        for(int i = 2; i<= n; i++){
            primes[i] = 1;
        }

        // TC -> O(Nlog(log(N)))
        for(int i = 2; i*i <= n; i++){ // sqrt(N)
            if(primes[i] == 1){
                for(int j = i*i; j<= n; j+= i){
                    primes[j] = 0;
                }
            }
        }

        // O(N)
        for(int i = 2; i< n; i++){
            if(primes[i] == 1)
                count++;
        }
        // total TC = O(2N) + Nlog(logN)
        return count;
    }
}