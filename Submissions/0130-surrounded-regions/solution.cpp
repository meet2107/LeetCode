class Solution {
public:

    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    int m,n;

    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<char>> &board){
        vis[r][c] = 1;

        for(int i=0;i<4;i++){
            int nr = r+dx[i];
            int nc = c+dy[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(nr,nc,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int j=0; j<n; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, vis, board);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1, j, vis, board);
            }
        }
        
        for(int i=0; i<m; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i, n-1, vis, board);
            }
        }


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
