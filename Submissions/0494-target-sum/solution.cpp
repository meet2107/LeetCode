class Solution {
public:

    int f(int ind, vector<int> &nums, vector<vector<int>> &dp, int tar, int sum){
        if(ind < 0){
            return sum == tar;
        }

        if(dp[ind][sum+1000] != -1){ // +1000 because sum can be negative too
            return dp[ind][sum+1000];
        }

        int add = f(ind-1,nums,dp,tar,sum+nums[ind]);
        int sub = f(ind-1,nums,dp,tar,sum-nums[ind]);

        return dp[ind][sum+1000] = add+sub; 
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2001,-1));
        return f(n-1,nums,dp,target,0);
    }
};
