#include <cstdio>
#include <algorithm>

using namespace std;
struct query {
    int p, q, r, id;
};
bool comp(const query& a, const query& b) {
    if (a.p == b.p) return a.q < b.q;
    return a.p < b.p;
}
bool comp2(const query& a, const query& b) {
    return a.id < b.id;
}

int n, m, k;
int a[100000], b[100000];
query nq[100000];

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0; i<n; i++) scanf("%d%d", &a[i], &b[i]);
    for (int i=0; i<m; i++) {
        int p, q, r;
        scanf("%d%d%d", &p, &q, &r);
        nq[i].p = p; nq[i].q = q; nq[i].r = r;
        nq[i].id = i;
    }
    sort(nq, nq+m, comp);   // 台風順に並び替え -> 順番に処理する
    // 2分探索？
}
