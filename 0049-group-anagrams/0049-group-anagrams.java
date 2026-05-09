class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> mp = new HashMap<>();
        
        for(String s : strs){
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            
            String temp = new String(arr);
            if(!mp.containsKey(temp)){
                mp.put(temp, new ArrayList<>());
            }
            // mp.putIfAbsent(temp, new ArrayList<>());
            mp.get(temp).add(s);
        }
        return new ArrayList<>(mp.values());
    }
}