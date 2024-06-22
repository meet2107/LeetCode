class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == temp){
                ans++;
                temp = 1 - temp;
            }
        }

        return ans;
    }
};
