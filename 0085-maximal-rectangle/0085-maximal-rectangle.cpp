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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> preSm(m,vector<int>(n));

        for(int j = 0; j<n; j++){
            int sm = 0;
            for(int i = 0; i<m; i++){
                sm += matrix[i][j]-'0';
                if(matrix[i][j] == '0')
                    sm = 0;
                preSm[i][j] = sm;
            }
        }
        int mxArea = 0;
        for(int i = 0; i<m; i++){
            int currArea = largestRectangleArea(preSm[i]);
            mxArea = max(mxArea, currArea);
        }
        return mxArea;
    }
};