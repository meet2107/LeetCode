class Solution {
public:

    int f(int ind, vector<int> &coins, int tar, vector<vector<int>> &dp){
        if(ind==0){
            if(tar % coins[0] == 0){
                return tar/coins[0];
            }
            else{
                return 1e9;
            }
        }
        // if(tar == 0){
        //     return 0;
        // }
        if(dp[ind][tar] != -1){
            return dp[ind][tar];
        }

        int ntk = f(ind-1,coins,tar,dp);
        int tk = 1e9;
        if(coins[ind] <= tar){
            tk = 1 + f(ind,coins,tar-coins[ind],dp);
        }

        return dp[ind][tar] = min(tk,ntk);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans = f(n-1,coins,amount,dp);

        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};
