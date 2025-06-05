class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    continue;
                }

                int dx[] = {-1,1,0,0};
                int dy[] = {0,0,-1,1};

                for(int ind=0;ind<4;ind++){
                    int nr = i+dx[ind];
                    int nc = j+dy[ind];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        ds.unionBySize(i*n+j,nr*n+nc);
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    continue;
                }

                int dx[] = {-1,1,0,0};
                int dy[] = {0,0,-1,1};

                set<int> compo;

                for(int ind=0;ind<4;ind++){
                    int nr = i+dx[ind];
                    int nc = j+dy[ind];

                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                        compo.insert(ds.findUPar(nr*n + nc));
                    }
                }

                int total = 0;
                for(auto it : compo){
                    total += ds.size[it];
                }

                ans = max(ans,total+1); // +1 for the 0 itself
            }
        }

        // if grid has only ones
        int c1 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    c1++;
                }
            }
        }

        if(c1 == n*n){
            ans = n*n;
        }

        return ans;
    }
};
