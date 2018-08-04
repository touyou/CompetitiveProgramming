#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> s;
int main() {
    int dirs[4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        s.push_back(tmp);
    }
    int dp[n][m][2];
    for (int i = 0; i < n; i++) {
        dp[i][0][0] = dp[i][0][1] = s[i][0] == '.' ? 1 : 0;
    }
    for (int i = 0; i < m; i++) {
        dp[0][i][0] = dp[0][i][1] = s[0][i] == '.' ? 1 : 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s[i][j] == '.') {
                dp[i][j][0] = dp[i][j-1][0] + 1;
            } else {
                dp[i][j][0] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                dp[i][j][1] = dp[i-1][j][1] + 1;
            } else {
                dp[i][j][1] = 0;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    // k 0 right 1 down 2 left 3 up
                    int cnt = 0;
                    int ny = i + dirs[k][0];
                    int nx = j + dirs[k][1];
                    while (ny >= 0 && ny < n && nx >= 0 && nx < m && s[ny][nx] == '.') {
                        int nny = ny + dirs[(k+1)%4][0];
                        int nnx = nx + dirs[(k+1)%4][1];
                        while (nny >= 0 && nny < n && nnx >= 0 && nnx < m && s[nny][nnx] == '.') {
                            res++;
                            nny += dirs[(k+1)%4][0];
                            nnx += dirs[(k+1)%4][1];
                        }
                        ny += dirs[k][0];
                        nx += dirs[k][1];
                    }
                }
            }
        }
    }
    printf("%d\n", res);
}
