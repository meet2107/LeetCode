class Solution {
public:

    // int help(vector<int> &nums,int ind,int jumps, vector<vector<int>> &dp){
    //     if(ind >= nums.size()-1){
    //         return jumps;
    //     }

    //     if(dp[ind][jumps] != -1){
    //         return dp[ind][jumps];
    //     }

    //     int mini = INT_MAX;
    //     for(int i=1;i<=nums[ind];i++){
    //         mini = min(mini,help(nums,ind+i,jumps+1,dp));
    //     }

    //     return dp[ind][jumps] = mini;
    // }

    int jump(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return help(nums,0,0,dp);

        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for(int i = 0; i < n; i++) {
            if(dp[i] == INT_MAX) continue;
            
            for(int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        
        return dp[n-1];
    }
};
