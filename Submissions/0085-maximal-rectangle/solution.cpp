class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> prev(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            vector<int> curr(cols, 0);
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    curr[j] = prev[j] + 1;
            }

            int rowArea = largestRectangleArea(curr);
            maxArea = max(maxArea, rowArea);

            prev = curr;
        }

        return maxArea;
    }
};
