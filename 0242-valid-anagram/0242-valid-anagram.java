class Solution {
    public boolean isAnagram(String s, String t) {
        int[] mp = new int[26];
        for(int i = 0; i<s.length(); i++){
            mp[s.charAt(i)-'a']++;
        }
        for(int j = 0; j<t.length(); j++){
            mp[t.charAt(j)-'a']--;
            if(mp[t.charAt(j)-'a'] < 0){
                return false;
            }
        }
        for(int i = 0; i<26; i++){
            if(mp[i] != 0)
                return false;
        }
        return true;
    }
}