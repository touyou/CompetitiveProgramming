#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c;
  int a[20][20], b[20];
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < m; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int res = 0;
    for (int j = 0; j < m; j++) res += a[i][j] * b[j];
    if (res + c > 0) ans++;
  }
  printf("%d\n", ans);
}
