class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> mp = new HashMap<>();
        
        for(String s : strs){
            int[] arr = new int[26];
            for(char ch : s.toCharArray()){
                arr[ch-'a']++;
            }
            
            String temp = Arrays.toString(arr);
            if(!mp.containsKey(temp)){
                mp.put(temp, new ArrayList<>());
            }
            // mp.putIfAbsent(temp, new ArrayList<>());
            mp.get(temp).add(s);
        }
        return new ArrayList<>(mp.values());
    }
}