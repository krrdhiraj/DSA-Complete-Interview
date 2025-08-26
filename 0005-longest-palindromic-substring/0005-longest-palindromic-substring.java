class Solution {
    public boolean isPalindrome(String s){
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++; j--;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        int n = s.length();
        String ans = "";
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                String temp = s.substring(i, j+1);
                if(isPalindrome(temp)){
                    if(temp.length() > ans.length()){
                        ans = temp;
                    }
                }
            }
        }
        return ans;
    }
}