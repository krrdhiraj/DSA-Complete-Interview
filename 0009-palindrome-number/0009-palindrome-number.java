class Solution {
    public boolean isPalindrome(int x) {
        String s = Integer.toString(x);

        int i= 0, j = s.length()-1;

        while(i < j){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;j--;
        }
        return true;
    }
}