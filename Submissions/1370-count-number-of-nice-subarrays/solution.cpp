class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans=0;
        map<int,int> m;
        m[0] = 1;
        int odd = 0;

        for(int i=0;i<n;i++){
            odd += nums[i] & 1;
            if(odd - k >= 0){
                ans += m[odd-k];
            }

            m[odd]++;
        }

        return ans;

    }
};
