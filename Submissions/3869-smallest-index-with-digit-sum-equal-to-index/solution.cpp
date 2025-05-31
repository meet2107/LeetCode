class Solution {
public:

    int digit(int n){
        int ans = 0;
        while(n){
            ans += n%10;
            n /= 10;
        }

        return ans;
    }
    
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for(int i=0;i<n;i++){
            if(digit(nums[i]) == i){
                ans = i;
                break;
            }
        }

        return ans;
    }
};
