class Solution {
public:

    int f(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(ind >= n){
            return 0;
        }

        if(dp[ind][buy] != -1){
            return dp[ind][buy];
        }

        int profit = 0;
        if(buy){
            profit = max(f(ind+1,0,prices,n,dp)-prices[ind],f(ind+1,1,prices,n,dp)); // buy or not buy
        }
        else{
            profit = max(f(ind+2,1,prices,n,dp)+prices[ind],f(ind+1,0,prices,n,dp)); // sell or not sell
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> f1(2,0), f2(2,0), cur(2,0); // f1 -> 1 step, f2 -> 2 step

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy){
                    profit = max(f1[1],f1[0]-prices[ind]);
                }
                else{
                    profit = max(f1[0],f2[1]+prices[ind]);
                }
                cur[buy] = profit;
            }
            f2 = f1;
            f1 = cur;
        }

        return cur[1];
    }
};
