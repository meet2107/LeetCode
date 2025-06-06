class Solution {
public:

    // int f(int row, int col, vector<vector<int>> &dp){
    //     if(row==0 && col==0){
    //         return 1;
    //     }
    //     if(row<0 || col<0){
    //         return 0;
    //     }

    //     if(dp[row][col] != -1){
    //         return dp[row][col];
    //     }

    //     int up = f(row-1,col,dp);
    //     int left = f(row,col-1,dp);

    //     return dp[row][col] = up+left;
    // }

    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;
                if(i>0){
                    up = prev[j];
                }
                if(j>0){
                    left = temp[j-1];
                }

                temp[j] = left+up;
            }
            prev = temp;
        }

        return prev[n-1];
    }
};
