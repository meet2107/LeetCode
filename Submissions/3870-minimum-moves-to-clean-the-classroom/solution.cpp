/*
███╗░░░███╗███████╗███████╗████████╗
████╗░████║██╔════╝██╔════╝╚══██╔══╝
██╔████╔██║█████╗░░█████╗░░░░░██║░░░
██║╚██╔╝██║██╔══╝░░██╔══╝░░░░░██║░░░
██║░╚═╝░██║███████╗███████╗░░░██║░░░
╚═╝░░░░░╚═╝╚══════╝╚══════╝░░░╚═╝░░░ */

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
#define Meet_Andharia                                                          \
    ios_base ::sync_with_stdio(false);                                         \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);
#define ll long long int
#define lld long double
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<long long int>
#define fori1(l, n) for (int i = 1; i < n; i++)
#define fori(o, n) for (ll i = 0; i < n; i++)
#define forii(l, r) for (ll i = l; i < r; i++)
#define forimn(m, n) for (int i = m; i <= n; i++)
#define forj(m, n) for (int j = m; j < n; j++)
#define forir(m, n) for (int i = n - 1; i >= m; i--)
#define forjr(m, n) for (int j = n - 1; j >= m; j--)
#define forje(m, n) for (int j = m; j <= n; j++)
#define fork(m, n) for (int k = m; k < n; k++)
#define forl(m, n) for (int l = m; l < n; l++)
#define loopi(v) for (auto i : v)
#define fi first
#define se second
#define in(n)                                                                  \
    int n;                                                                     \
    cin >> n;
#define inll(n)                                                                \
    ll n;                                                                      \
    cin >> n;
#define instr(n)                                                               \
    string n;                                                                  \
    cin >> n;
#define inarr(arr, n)                                                          \
    long long int arr[n];                                                      \
    for (int i = 0; i < n; i++)                                                \
        cin >> arr[i];
#define outarr(arr, n)                                                         \
    for (int i = 0; i < n; i++) {                                              \
        cout << arr[i] << " ";                                                 \
    }                                                                          \
    cout << endl;
#define pyes cout << "YES\n";
#define pno cout << "NO\n";
#define pneg1 cout << "-1\n";
#define p0 cout << "0\n";
#define CASE(x) cout << "Case #" << x << ": ";
#define all(v) v.begin(), v.end()

const ll MOD = 1000000007LL;
const ll MOD2 = 998244353;
const ll inf = 1e18;
const int N = 120;

class Solution {
public:
    int minMoves(vector<string>& t, int energy) {
        //vector<string> t = c;
        int m = t.size();
        int n = t[0].size();
        int sx = 0, sy = 0;
        vector<pair<int, int>> l;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (t[i][j] == 'L') {
                    l.emplace_back(i, j);
                }
                if (t[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        int lit = (int)l.size();
        int temp = (1 << lit) - 1;

        vector<vector<vector<int>>> maxEnergyVisited(
            m, vector<vector<int>>(n, vector<int>(temp + 1, -1)));

        queue<array<int, 5>> q;
        q.push({sx, sy, 0, 0, energy});
        maxEnergyVisited[sx][sy][0] = energy;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            int x = f[0];
            int y = f[1];
            int litt = f[2];
            int stp = f[3];
            int e = f[4];

            if (litt == temp) {
                return stp;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int ne = e - 1;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || ne < 0 ||
                    t[nx][ny] == 'X') {
                    continue;
                }

                if (t[nx][ny] == 'R') {
                    ne = energy;
                }

                int nlitt = litt;
                for (int j = 0; j < lit; ++j) {
                    if (l[j].first == nx && l[j].second == ny) {
                        nlitt |= (1 << j);
                    }
                }

                if (ne > maxEnergyVisited[nx][ny][nlitt]) {
                    maxEnergyVisited[nx][ny][nlitt] = ne;
                    q.push({nx, ny, nlitt, stp + 1, ne});
                }
            }
        }

        return -1;
    }
};
