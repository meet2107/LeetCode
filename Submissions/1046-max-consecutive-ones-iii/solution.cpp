class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int c0 = 0;
        int ans = 0;

        for(int right = 0; right < n; right++){
            if(nums[right] == 0){
                c0++;
            }

            if(c0 > k){
                if(nums[left] == 0){
                    c0--;
                }
                left++;
            }

            ans = max(ans,right-left+1);
            // left++;
        }

        return ans;
    }
};
