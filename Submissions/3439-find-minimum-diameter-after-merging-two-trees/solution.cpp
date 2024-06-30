class Solution {
public:
    int tree_diameter(const vector<vector<int>>& tree) {
        int n = tree.size();
        if (n == 1)
            return 0;

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;
        int fn = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int n : tree[node]) {
                if (dist[n] == -1) {
                    dist[n] = dist[node] + 1;
                    q.push(n);
                    if (dist[n] > dist[fn]) {
                        fn = n;
                    }
                }
            }
        }

        q.push(fn);
        dist.assign(n, -1);
        dist[fn] = 0;
        int d = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int n : tree[node]) {
                if (dist[n] == -1) {
                    dist[n] = dist[node] + 1;
                    q.push(n);
                    d = max(d, dist[n]);
                }
            }
        }

        return d;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> tree1(n);
        vector<vector<int>> tree2(m);

        for (const auto& edge : edges1) {
            tree1[edge[0]].push_back(edge[1]);
            tree1[edge[1]].push_back(edge[0]);
        }

        for (const auto& edge : edges2) {
            tree2[edge[0]].push_back(edge[1]);
            tree2[edge[1]].push_back(edge[0]);
        }

        int d1 = tree_diameter(tree1);
        int d2 = tree_diameter(tree2);

        return max({d1, d2,
                    (d1 + 1) / 2 + 1 + (d2 + 1) / 2});
    }
};
