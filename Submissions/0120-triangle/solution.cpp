class Solution {
public:

    int f(int r, int c, vector<vector<int>> &a, vector<vector<int>> &dp){
        if(r == a.size()-1){
            return a[r][c];
        }

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        int d = a[r][c] + f(r+1,c,a,dp);
        int dg = a[r][c] + f(r+1,c+1,a,dp);

        return dp[r][c] = min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};
