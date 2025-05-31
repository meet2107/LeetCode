class Solution {
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, 1, -1, 0};
    int m, n;

    bool isvalid(int x, int y) { return x >= 0 && y >= 0 && x < m && y < n; }

    int minMoves(vector<string>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        if (matrix[m - 1][n - 1] == '#')
            return -1;

        vector<vector<pair<int, int>>> portals(26);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isalpha(matrix[i][j]))
                    portals[matrix[i][j] - 'A'].push_back({i, j});
            }
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<bool> used(26, false);
        deque<vector<int>> dq;
        dq.push_front({0, 0, 0});

        while (!dq.empty()) {
            vector<int> curr = dq.front();
            dq.pop_front();
            int moves = curr[0], i = curr[1], j = curr[2];

            if (i == m - 1 && j == n - 1)
                return moves;

            if (vis[i][j])
                continue;

            vis[i][j] = true;

            if (isalpha(matrix[i][j])) {
                int portalID = matrix[i][j] - 'A';
                if (!used[portalID]) {
                    used[portalID] = true;
                    for (auto& [x, y] : portals[portalID]) {
                        if (!vis[x][y]) {
                            dq.push_front({moves, x, y});
                        }
                    }
                }
            }

            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (isvalid(x, y) && !vis[x][y] && matrix[x][y] != '#') {
                    dq.push_back({moves + 1, x, y});
                }
            }
        }

        return -1;
    }
};
