class Solution {
public:

    int f(int ind, int buy, int tran, vector<int> &prices, int n, vector<vector<vector<int>>> &dp){
        if(ind == n || tran == 0){
            return 0;
        }

        if(dp[ind][buy][tran] != -1){
            return dp[ind][buy][tran];
        }

        int profit = 0;
        if(buy){
            profit = max(f(ind+1,0,tran,prices,n,dp)-prices[ind],f(ind+1,1,tran,prices,n,dp)); // buy or not buy
        }
        else{
            profit = max(f(ind+1,1,tran-1,prices,n,dp)+prices[ind],f(ind+1,0,tran,prices,n,dp)); // sell or not sell, reduce number of tran when we sell the stock
        }

        return dp[ind][buy][tran] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int tran=1;tran<=k;tran++){
                    if(buy){
                        dp[ind][buy][tran] = max(dp[ind+1][1][tran], dp[ind+1][0][tran]-prices[ind]);
                    }
                    else{
                        dp[ind][buy][tran] = max(dp[ind+1][1][tran-1]+prices[ind],dp[ind+1][0][tran]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};
