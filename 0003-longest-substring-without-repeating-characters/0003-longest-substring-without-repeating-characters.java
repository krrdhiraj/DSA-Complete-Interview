class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character > st  = new HashSet<>();

        int i = 0, j = 0, maxLen = 0;
        while(j < s.length()){
            char ch = s.charAt(j);
            while(st.contains(ch)){
                st.remove(s.charAt(i));
                i++;
            }
            maxLen = Math.max(maxLen, j-i+1);
            st.add(ch);
            j++;
        }
        return maxLen;
    }
}