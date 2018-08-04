#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool dp[1000][1000];
int rev(int n) {
    if (n < 10) return n;
    if (n < 100) {
        return 10 * (n % 10) + n / 10;
    }
    return 100 * (n % 10) + 10 * ((n % 100) / 10) + n / 100;
}
vector<pii> is_inf(int x, int y, vector<pii> visited) {
    int nx, ny;
    if (x < y) {
        nx = rev(x);
        ny = y;
    } else {
        nx = x;
        ny = rev(y);
    }
    if (nx > ny) nx -= ny;
    else ny -= nx;
    if (nx < 10 || ny < 10) return vector<pii>();
    if (dp[nx][ny]) return visited;
    bool flag = false;
    for (int i = 0; i < visited.size(); i++) {
        pair<int, int> p = visited[i];
        if ((p.first == nx && p.second == ny) || (p.first == ny && p.second == nx)) {
            flag = true;
            break;
        }
    }
    visited.push_back(pii(nx, ny));
    if (flag) return visited;
    return is_inf(nx, ny, visited);
}
int main() {
    for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) {
        dp[i][j] = false;
    }
    for (int i = 0; i < 1000; i++) for (int j = 0; j < 1000; j++) {
        if (dp[i][j]) continue;
        vector<pii> vec;
        vec.push_back(pii(i,j));
        vec = is_inf(i, j, vec);
        for (int k = 0; k < vec.size(); k++) {
            dp[vec[k].first][vec[k].second] = dp[vec[k].second][vec[k].first] = true;
        }
    }
    int n, m; scanf("%d%d", &n, &m);
    int res = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j]) res++;
        }
    }
    printf("%d\n", res);
}
