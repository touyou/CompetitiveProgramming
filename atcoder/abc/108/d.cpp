#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main() {
    int l;
    scanf("%d", &l);
    int n = 0;
    int tmp = l;
    while (tmp > 0) {
        tmp /= 2;
        n++;
    }
    n += 2;
    vector<pair<int, pii> > edge;
    int mdist[n + 2] = {0};
    for (int i = 2; i <= n; i++) {
        edge.push_back(pair<int, pii>(1, pii(i, 0)));
    }
    int len = 1;
    for (int i = n - 1; i >= 2; i--) {
        for (int j = i + 1; j <= n; j++) {
            if (mdist[j] + len < l) {
                edge.push_back(pair<int, pii>(i, pii(j, len)));
                mdist[i] = max(mdist[i], mdist[j] + len);
            }
        }
        len *= 2;
    }
    sort(edge.begin(), edge.end());
    printf("%d %d\n", n, edge.size());
    for (int i = 0; i < edge.size(); i++) {
        printf("%d %d %d\n", edge[i].first, edge[i].second.first, edge[i].second.second);
    }
}
