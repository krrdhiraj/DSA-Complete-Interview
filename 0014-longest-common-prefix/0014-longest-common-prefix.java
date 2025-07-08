class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        if(n == 0)
            return "";
        
        Arrays.sort(strs);
        String common = strs[0];
        for(int i = 0; i<common.length(); i++){
            for(int j = 1; j<n; j++){
                String word = strs[j];
                if(i == word.length() || common.charAt(i) != word.charAt(i)){
                    return common.substring(0, i);
                }
            }
        }
        return common;
    }
}