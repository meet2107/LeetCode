class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty()){
            auto f = q.front();
            q.pop();
            int x = f.first.first;
            int y = f.first.second;
            int steps = f.second;

            ans[x][y] = steps;

            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny]==0){
                    vis[nx][ny] = 1;
                    q.push({{nx,ny},steps+1});
                }
            }
        }

        return ans;
    }
};
