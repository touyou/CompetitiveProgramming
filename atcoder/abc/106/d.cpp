#include <bits/stdc++.h>
using namespace std;
int n, m, q;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    int tcnt[512][512] = {0};
    int query[512][512] = {0};
    for (int i = 0; i < m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        tcnt[l][l]++;
        tcnt[l][r+1]--;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tcnt[i][j] += tcnt[i][j-1];
        }
    }
    
    int upcnt[512][512] = {0}, dwncnt[512][512] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n+1; j++) {
            upcnt[i][j] = upcnt[i][j-1];
            dwncnt[i][j] = dwncnt[i][j-1];
            if (tcnt[i][j] > tcnt[i][j-1]) upcnt[i][j] += tcnt[i][j] - tcnt[i][j-1];
            if (tcnt[i][j] < tcnt[i][j-1]) dwncnt[i][j] += tcnt[i][j-1] - tcnt[i][j];
        }
    }

    for (int pi = 1; pi <= n; pi++) {
        for (int qi = pi; qi <= n; qi++) {
            for (int i = pi; i <= qi; i++) {
                query[pi][qi] += min(upcnt[i][qi+1], dwncnt[i][qi+1]);
            }
        }
    }


    for (int i = 0; i < q; i++) {
        int pi, qi; scanf("%d%d", &pi, &qi);
        printf("%d\n", query[pi][qi]);
    }
}
