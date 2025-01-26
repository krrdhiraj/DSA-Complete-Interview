class Solution {
    public int romanToInt(String s) {
        int n = s.length();
        Map<Character,Integer> mp = Map.of(
            'I',1,
            'V',5,
            'X',10,
            'L', 50,
            'C', 100,
            'D', 500,
            'M', 1000
            );
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(i+1 < n && mp.get(s.charAt(i)) < mp.get(s.charAt(i+1))){
                ans += mp.get(s.charAt(i+1)) - mp.get(s.charAt(i));
                i++;
            }else{
                ans += mp.get(s.charAt(i));
            }
        }
        return ans;
    }
}