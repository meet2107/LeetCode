class Solution {
public:

    int help(vector<int> &nums, int start, int end){
        // int n = nums.size();
        int prev = 0;
        int maxi = 0;

        for(int i=start;i<=end;i++){
            int temp = max(maxi,prev+nums[i]);
            prev = maxi;
            maxi = temp;
        }

        return maxi;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }

        return max(help(nums,0,n-2),help(nums,1,n-1));
    }
};
