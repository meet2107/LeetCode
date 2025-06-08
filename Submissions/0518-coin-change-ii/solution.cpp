class Solution {
public:

    int f(int ind, vector<int> &coins, int tar, vector<vector<int>> &dp){
        if(ind==0){
            return (tar % coins[0] == 0);
        }
        // if(tar == 0){
        //     return 0;
        // }
        if(dp[ind][tar] != -1){
            return dp[ind][tar];
        }

        int ntk = f(ind-1,coins,tar,dp);
        int tk = 0;
        if(coins[ind] <= tar){
            tk = f(ind,coins,tar-coins[ind],dp);
        }

        return dp[ind][tar] = tk + ntk;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        //int ans = f(n-1,coins,amount,dp);

        return f(n-1,coins,amount,dp);
    }
};
