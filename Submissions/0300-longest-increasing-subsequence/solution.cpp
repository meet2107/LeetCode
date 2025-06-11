class Solution {
public:

    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp, int n){
        if(ind == n){
            return 0;
        }

        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }

        int ntk = f(ind+1,prev,nums,dp,n);

        int tk = 0;
        if(prev==-1 || nums[ind] > nums[prev]){
            tk = 1 + f(ind+1,ind,nums,dp,n);
        }

        return dp[ind][prev+1] = max(tk,ntk);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return temp.size();
    }
};
