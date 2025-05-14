class Solution {
public:

    void help(vector<int> &a, vector<vector<int>> &ans, vector<int> &temp, int target, int sum, int ind){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        if(sum > target || ind >= a.size()){
            return;
        }

        temp.push_back(a[ind]);
        help(a,ans,temp,target,sum+a[ind],ind);
        temp.pop_back();
        help(a,ans,temp,target,sum,ind+1);
    }

    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        help(a,ans,temp,target,0,0);
        return ans;
    }
};
