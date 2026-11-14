class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        String s1 = strs[0];
        for(int j = 0; j<s1.length(); j++){
            for(int i = 1; i<n; i++){
                String s2 = strs[i];
                if(s2.length() == j || s2.charAt(j) != s1.charAt(j)){
                    return s1.substring(0,j);
                }
            }
        }
        return s1;
    }
}