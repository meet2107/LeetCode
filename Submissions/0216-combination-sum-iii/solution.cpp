class Solution {
public:

    void help(int ind, int sum, vector<int> &a, vector<vector<int>> &ans, vector<int> &temp, int n, int k){
        if(sum == n){
            if(temp.size() == k){
                ans.push_back(temp);
                return;
            }
        }

        if(sum > n && ind >= a.size()){
            return;
        }

        for(int i=ind;i<a.size();i++){
            if(i > ind && a[i] == a[i-1]){
                continue;
            }

            temp.push_back(a[i]);
            help(i+1,sum+a[i],a,ans,temp,n,k);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> a;
        for(int i=1;i<=9;i++){
            a.push_back(i);
        }

        vector<vector<int>> ans;
        vector<int> temp;

        help(0,0,a,ans,temp,n,k);
        return ans;
    }
};
