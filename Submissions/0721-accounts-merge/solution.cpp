class DisjointSet {
    vector<int> rank, parent, size;
public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j]) == m.end()){
                    m[accounts[i][j]] = i;
                }
                else{
                    ds.unionBySize(i,m[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> mergedmails(n);
        for(auto it : m){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedmails[node].push_back(mail);
        }

        for(int i=0;i<n;i++){
            for(auto it : mergedmails[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergedmails[i].size() == 0){
                continue;
            }
            sort(mergedmails[i].begin(),mergedmails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergedmails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
