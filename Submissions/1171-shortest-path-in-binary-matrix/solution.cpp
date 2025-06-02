class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0){
            return -1;
        }

        set<pair<int,pair<int,int>>> s;
        s.insert({0,{0,0}}); // r,c,dis

        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0] = 0;

        int dx[] = {0,0,-1,1,-1,-1,1,1};
        int dy[] = {-1,1,0,0,-1,1,1,-1};

        while(!s.empty()){
            auto b = *s.begin();
            s.erase(b);

            int r = b.first;
            int c = b.second.first;
            int wt = b.second.second;

            for(int i=0;i<8;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(nr<0 || nr>=n || nc<0 || nc>=n || grid[nr][nc] == 1){
                    continue;
                }

                if(wt+1<dist[nr][nc]){
                    s.erase({nr,{nc,dist[nr][nc]}});
                    dist[nr][nc] = wt+1;
                    s.insert({nr,{nc,dist[nr][nc]}});
                }
            }
        }

        if(dist[n-1][n-1] == 1e9){
            return -1;
        }

        return dist[n-1][n-1]+1;
    }
};
