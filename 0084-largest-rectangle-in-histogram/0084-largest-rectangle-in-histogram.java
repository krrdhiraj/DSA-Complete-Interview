class Solution {
    int n;
    public void pse(int[] heights, int[] pse){
        Stack<Integer> st = new Stack<>();
        pse[0] = -1;
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.peek()] >= heights[i]){
                st.pop();
            }
            pse[i] = st.size() == 0 ? -1 : st.peek();
            st.push(i);
        }
        
    }
    public void nse(int[] heights, int[] nse){
        Stack<Integer> st = new Stack<>();
        nse[n-1] = n;
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && heights[st.peek()] >= heights[i]){
                st.pop();
            }
            nse[i] = st.size() == 0 ? n : st.peek();
            st.push(i);
        }
        
    }
    public int largestRectangleArea(int[] heights) {
        n = heights.length;
        int mxArea = 0;
        int[] nseA = new int[n];
        int[] pseA = new int[n];
        nse(heights, nseA);
        pse(heights, pseA);

        for(int i = 0 ; i<n; i++){
           
            mxArea = Math.max(mxArea, (heights[i] * (nseA[i]-pseA[i]-1)));
        }
        return mxArea;
    }
}