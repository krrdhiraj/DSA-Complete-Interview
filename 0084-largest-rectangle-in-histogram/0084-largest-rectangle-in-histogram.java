class Solution {
    
    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int mxArea = 0;
        Stack<Integer> st = new Stack<>();
        for(int i = 0 ; i<=n; i++){
           while(!st.empty() && (i == n || heights[st.peek()] >= heights[i])){
                int height = heights[st.peek()];
                st.pop();
                int width = st.size() == 0 ? i : i - st.peek()-1;

                mxArea = Math.max(mxArea, (height * width));
           }
           st.push(i);
        }
        return mxArea;
    }
}