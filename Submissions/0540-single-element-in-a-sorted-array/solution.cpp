class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low=0, high=n-1;

        while(low < high){
            int mid = (low + high)/2;

            if((mid%2 && nums[mid] == nums[mid-1]) || (mid%2==0 && nums[mid] == nums[mid+1])){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }

        return nums[low];
    }
};
