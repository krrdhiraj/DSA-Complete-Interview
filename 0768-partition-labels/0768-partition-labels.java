class Solution {
    public List<Integer> partitionLabels(String s) {
         int n = s.length();

        List<Integer> ans = new ArrayList<>();

       int[] mp = new int[26]; // storing last index of a char
        for(int i = 0; i<n; i++){
            mp[(s.charAt(i)-'a')] = i;
        }

        int i = 0;
        int start = 0, end = 0;
        while(i < n){
            end = Math.max(end, mp[(s.charAt(i)-'a')]);
            if( i == end){
                ans.add(end - start + 1);
                start = i + 1;
            }
            i++;
        }
        return ans;
    }
}