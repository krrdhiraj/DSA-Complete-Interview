class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int mxArea = 0;
        stack<int> st;
        for(int i = 0 ; i<=n; i++){
           while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width = st.size() == 0 ? i : i - st.top()-1;

                mxArea = max(mxArea, (height * width));
           }
           st.push(i);
        }
        return mxArea;
    }
};