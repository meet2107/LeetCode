class Solution {
public:

    vector<int> help(int row){
        long long ans = 1;
        vector<int> nrow;
        nrow.push_back(1);

        for(int col=1;col<row;col++){
            ans = ans*(row-col);
            ans /= col;
            nrow.push_back(ans);
        }

        return nrow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(help(i));
        }

        return ans;
    }
};
