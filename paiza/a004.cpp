#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> P;
int L, n, m;
int a, b, c;
P line[10000][100];
int main() {
    scanf("%d%d%d", &L, &n, &m);
    for (int i=0; i<m; i++) {
        for (int j=0; j<L; j++) {
            line[i][j] = P(-1, -1);
        }
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        line[a-1][b-1] = P(a, c-1);
        line[a][c-1] = P(a-1, b-1);
    }
    int d = L - 1, res = 0;
    while (d >= 0) {
        while (d >= 0 && line[res][d].first == -1 && line[res][d].second == -1) {
            d--;
            if (d >= 0 && line[res][d].first != -1) {
                break;
            }
        }
        if (d < 0) break;
        int tres = line[res][d].first;
        int td = line[res][d].second;
        // printf("%d %d\n",res, d);
        res = tres; d = td - 1;
    }
    printf("%d\n", res + 1);
}
