// http://poj.org/problem?id=1909
// 方針はプリントの通りにする
// #include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
int n, id, c, res;
int p[10010], m[10010], v[10010];
int main() {
    while(scanf("%d",&n)) {
        if (n==0) break;
        queue<int> q;
        for (int i=0; i<n; i++) {
            scanf("%d %d %d",&id,&m[i],&v[i]); m[i]--;
            for (int j=0; j<v[i]; j++) {
                scanf("%d",&c);
                p[c-1] = i;
            }
            if (v[i] == 0) q.push(i);
        }
        res = 0;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            int pi = p[i];
            m[pi] += m[i];
            res += abs(m[i]);
            v[pi]--;
            if (v[pi] == 0) q.push(pi);
        }
        printf("%d\n",res);
    }
}
