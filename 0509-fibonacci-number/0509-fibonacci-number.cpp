class Solution {
public:
    int helper(int n, vector<int>&mem){
        if(n <= 1)  return n;

        if(mem[n] =! -1)
            return mem[n];
        return mem[n] = fib(n-1)+ fib(n-2);
    }
    int fib(int n) {

        if(n <= 1)  return n;
        vector<int> mem(n+1, -1);
        helper(n, mem);
        return mem[n];
    }
};