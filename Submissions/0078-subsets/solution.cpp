class Solution {
public:

    void help(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int index){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        help(nums,ans,temp,index+1);
        temp.push_back(nums[index]);
        help(nums,ans,temp,index+1);
        temp.pop_back();
        // help(nums,ans,temp,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        help(nums, ans, temp, 0);

        return ans;
    }
};
