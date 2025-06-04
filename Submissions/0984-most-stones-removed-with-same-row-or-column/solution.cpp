class DSU{
    vector<int> parent,size;
public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }

    void unite(int u, int v){
        int upar = findPar(u);
        int vpar = findPar(v);

        if(upar == vpar){
            return;
        }

        if(size[upar] <= size[vpar]){
            parent[upar] = vpar;
            size[vpar] += size[upar];
        }
        else{
            parent[vpar] = upar;
            size[upar] += size[vpar];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); // total stones

        // dimensions nthi apya matrix na, find last stone's row col
        int row = 0;
        int col = 0;

        for(auto it : stones){
            row = max(row,it[0]);
            col = max(col,it[1]);
        }

        DSU ds(row+col+1);
        map<int,int> m; // row and col jema stones che

        for(auto it : stones){
            int r = it[0];
            int c = it[1] + row + 1; // 1D array ma convert krva, 0,1,...,row, (col num)+row+1
            m[r] = 1;
            m[c] = 1;

            ds.unite(r,c);
        }

        int stoneComp = 0; // total stone components
        for(auto it : m){
            if(ds.findPar(it.first) == it.first){
                stoneComp++;
            }
        }

        return n-stoneComp; // kem k badha components ma single stone evo rese je nai upadi shakai
    }
};
