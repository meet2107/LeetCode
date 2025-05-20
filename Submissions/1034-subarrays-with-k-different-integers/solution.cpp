class Solution {
public:

    int help(vector<int> &nums, int k){
        int n = nums.size();

        map<int,int> m;
        int cnt = 0;
        int i=0,j=0;
        while(j < n){
            m[nums[j]]++;

            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]] == 0){
                    m.erase(nums[i]);
                }
                i++;
            }

            cnt += j-i+1;
            j++;
        }

        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return help(nums,k) - help(nums,k-1);
    }
};
