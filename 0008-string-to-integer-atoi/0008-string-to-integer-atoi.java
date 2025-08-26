class Solution {
    public int myAtoi(String s) {
        int i = 0;
        int n = s.length();
        while(i < n && s.charAt(i) == ' '){
            i++;
        }
        if(i == n){
            return 0;
        }
        long ans = 0;
        
        boolean neg = false;
        for(int j = i; j<n; j++){
            char ch = s.charAt(j);
            if(j == i){
                if(ch == '-'){
                    neg = true;
                    continue;
                }else if(ch == '+'){
                    neg = false;
                    continue;
                }
            }
            if(ch >= '0' && ch <= '9'){
                ans = ans*10 + ch-'0';

                if(neg){
                    long negAns = -ans;
                    if(negAns < Integer.MIN_VALUE){
                        return Integer.MIN_VALUE;
                    }
                }else{
                    if(ans > Integer.MAX_VALUE){
                        return Integer.MAX_VALUE;
                    }
                }
            }else{
                break;
            }
        }
        if(neg){
            ans = -ans;
        }
        return (int)ans;
    }
}