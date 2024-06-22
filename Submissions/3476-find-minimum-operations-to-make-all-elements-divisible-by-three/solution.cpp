class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(auto i : nums){
            int t = i%3;

            if(t==1){
                ans++;
            }
            else if(t==2){
                ans++;
            }
        }

        return ans;
    }
};
