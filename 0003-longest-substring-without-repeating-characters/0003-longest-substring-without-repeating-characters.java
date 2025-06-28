class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;
        HashMap<Character, Integer> mp = new HashMap<>();

        while(j < n){
            char ch = s.charAt(j);
            mp.put(ch, mp.getOrDefault(ch,0)+1);
            if(mp.get(ch) >= 1){
                while(i < j && j-i+1 > mp.size()){
                    mp.put(s.charAt(i), mp.get(s.charAt(i))-1);
                    if(mp.get(s.charAt(i)) == 0){
                        mp.remove(s.charAt(i));
                    }
                    i++;
                }
                ans = Math.max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
}