class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 0){
                    cnt++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        int rotten=0,time=0;
        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};

        while(!q.empty()){
            int k = q.size();
            rotten += k;

            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1){
                        continue;
                    }

                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()){
                time++;
            }
        }

        return cnt == rotten ? time : -1;
    }
};
