class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // Copy the matrix
        
        // Fill dp table from second row onwards
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int ld = (j > 0) ? dp[i-1][j-1] : 1e9;
                int rd = (j < n-1) ? dp[i-1][j+1] : 1e9;
                
                dp[i][j] = matrix[i][j] + min({up, ld, rd});
            }
        }
        
        // Find minimum in last row
        int ans = dp[n-1][0];
        for(int j = 1; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};

