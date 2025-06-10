class Solution {
public:
    bool f(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (s2[k] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j] || s2[j] == '?') {
            return dp[i][j] = f(s1, s2, i - 1, j - 1, dp);
        }

        if (s2[j] == '*') {
            return dp[i][j] = f(s1, s2, i - 1, j, dp) || f(s1, s2, i, j - 1, dp);
        }

        return dp[i][j] = 0;
    }

    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(s1, s2, n - 1, m - 1, dp);
    }
};

