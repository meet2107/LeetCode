class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));

        set<pair<int,pair<int,int>>> s;
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        s.insert({grid[0][0], {0,0}});
        vis[0][0] = 1;

        int maxEle = 0;

        while(!s.empty()){
            auto it = *s.begin();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            s.erase(it);

            maxEle = max(maxEle,t);
            if(r==n-1 && c==n-1){
                return maxEle;
            }

            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];

                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc] == 0){
                    vis[nr][nc] = 1;
                    s.insert({grid[nr][nc],{nr,nc}});
                }
            }
        }

        return -1;
    }
};
