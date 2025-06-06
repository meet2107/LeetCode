class Solution {
public:

    // int help(int n, vector<int> &dp){
    //     if(n == 0 || n==1){
    //         return 1;
    //     }
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     int one = help(n-1,dp);
    //     int two = help(n-2,dp);

    //     return dp[n] = one+two;
    // }

    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;

        for(int i=2;i<=n;i++){
            int cur = prev2 + prev;
            prev2 = prev;
            prev = cur;
        }

        return prev;
    }
};
