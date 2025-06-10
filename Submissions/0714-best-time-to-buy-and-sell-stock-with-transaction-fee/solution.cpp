class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> f1(2,0), cur(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit;
                if(buy){
                    profit = max(f1[1],f1[0]-prices[ind]);
                }
                else{
                    profit = max(f1[0],f1[1]+prices[ind]-fee);
                }
                cur[buy] = profit;
            }
            f1 = cur;
        }

        return cur[1];
    }
};
