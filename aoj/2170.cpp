// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2170
// マークのクエリー時に子供を更新する？
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int n, q;
int p[100010], nearest[100010];
ll res;
int main() {
    while (scanf("%d%d",&n,&q)) {
        if (n==0&&q==0) break;
        for (int i=1; i<=n; i++) {
            scanf("%d",&p[i]);
            nearest[i] = 1;
        }

    }
}
