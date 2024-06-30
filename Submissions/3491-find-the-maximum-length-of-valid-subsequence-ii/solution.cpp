class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        /*int n = nums.size();
        if(n<2) return n;

        int ans = 1;
        int cur = 1;

        for(int i=1;i<n;i++){
            if((nums[i] + nums[i-1]) % k == (nums[i-1] + (i > 1 ? nums[i-2] : 0)) % k){
                cur++;
            }
            else{
                cur=1;
            }
            ans = max(ans,cur);
        }

        return ans;*/

        vector<vector<int>> dp(k,vector<int>(k,0));
        int ans = 0;

        for(auto num : nums){
            for(int j=0;j<k;j++){
                int remainder = num%k;
                ans = max(ans,dp[remainder][j] = dp[j][remainder] + 1);
            }
        }

        return ans;
    }
};
