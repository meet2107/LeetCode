class Solution {
public:

    int help(vector<int> &nums, int msum){
        int n = nums.size();
        int part = 1;
        int sum = 0;

        for(int i=0;i<n;i++){
            if(sum + nums[i] <= msum){
                sum += nums[i];
            }
            else{
                part++;
                sum = nums[i];
            }
        }

        return part;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            int mid = (low + high)/2;

            if(help(nums,mid) > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;
    }
};
