class Solution {
    public int firstUniqChar(String s) {
        int n = s.length();
        int[] mp = new int[26];

        for(int i = 0; i<n; i++){
            mp[s.charAt(i)-'a']++;
        }

        for(int i = 0; i<n; i++){
            if(mp[s.charAt(i)-'a'] == 1)
                return i;
        }
        return -1;
    }
}