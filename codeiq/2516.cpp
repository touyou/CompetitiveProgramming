#include <bits/stdc++.h>
using namespace std;
int m, n;
string strMap[64];

int main() {
    scanf("%d%d", &m, &n);
    for (int i=0; i<m; i++) cin >> strMap[i];
    int res = bfs(
