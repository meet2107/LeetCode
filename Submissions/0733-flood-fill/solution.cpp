class Solution {
public:
    int m,n;

    void dfs(vector<vector<int>> &image, int row, int col, int ncolor, int dx[], int dy[], vector<vector<int>> &ans, int icolor){
        ans[row][col] = ncolor;

        for(int i=0;i<4;i++){
            int nr = row + dx[i];
            int nc = col + dy[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc] == icolor && ans[nr][nc] != ncolor){
                dfs(image,nr,nc,ncolor,dx,dy,ans,icolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        vector<vector<int>> ans = image;
        int ini = image[sr][sc];

        int dx[4] = {0,-1,0,1};
        int dy[4] = {-1,0,1,0};

        dfs(image,sr,sc,color,dx,dy,ans,ini);
        return ans;
    }
};
