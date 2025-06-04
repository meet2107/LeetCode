class DisjointSet{
    vector<int> parent,rank;
public:
    DisjointSet(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findPar(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findPar(u) == ds.findPar(v)){
                extra++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }  

        int comp = 0;
        for(int i=0;i<n;i++){
            if(ds.findPar(i) == i){
                comp++;
            }
        }

        if(extra >= comp-1){
            return comp-1;
        } 

        return -1;     
    }
};
