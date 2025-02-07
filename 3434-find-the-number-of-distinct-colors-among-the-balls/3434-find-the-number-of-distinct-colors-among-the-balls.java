class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int n = queries.length;
        int[] ans = new int[n];
        Map<Integer,Integer> cntColor = new HashMap<>();
        Map<Integer,Integer> trackBallColor = new HashMap<>();
        for(int i = 0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(trackBallColor.containsKey(ball)){// color already present
                int prevColor = trackBallColor.get(ball);
                trackBallColor.put(ball, color);
                int cnt = cntColor.get(prevColor)-1;
                if(cnt == 0){
                    cntColor.remove(prevColor);
                }else{
                    cntColor.put(prevColor, cnt);
                }
            }
            trackBallColor.put(ball,color);
            int cnt = cntColor.getOrDefault(color, 0) + 1;
            cntColor.put(color, cnt);
            ans[i] = cntColor.size();
        }
        return ans;
    }
}