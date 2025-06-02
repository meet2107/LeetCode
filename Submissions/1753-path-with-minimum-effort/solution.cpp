class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        set<pair<int, pair<int, int>>> s;
        dist[0][0] = 0;
        s.insert({0, {0, 0}}); // {effort, {row, col}}

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        while (!s.empty()) {
            auto it = *s.begin();
            s.erase(it);

            int effort = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == n - 1 && c == m - 1) return effort;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                int newEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));

                if (newEffort < dist[nr][nc]) {
                    s.erase({dist[nr][nc], {nr, nc}});
                    dist[nr][nc] = newEffort;
                    s.insert({newEffort, {nr, nc}});
                }
            }
        }

        return 0;
    }
};

