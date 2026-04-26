class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap<>();

        for(String s : strs){
            int[] freq = new int[26];
            for(char ch : s.toCharArray()){
                freq[ch-'a']++;
            }

            String str = Arrays.toString(freq);
            mp.putIfAbsent(str, new ArrayList<>());
            mp.get(str).add(s);
        }

        return new ArrayList<>(mp.values());
    }
}