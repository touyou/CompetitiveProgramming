#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int p[n];
  for (auto i = 0; i < n; i++)
    scanf("%d", &p[i]);
  int q[n];
  for (auto i = 0; i < n; i++)
    q[p[i] - 1] = i;
  int ret = 1, maxr = 0;
  for (auto i = 1; i < n; i++) {
    if (q[i] < q[i - 1]) {
      maxr = max(maxr, ret);
      ret = 1;
    } else {
      ret++;
    }
  }
  maxr = max(ret, maxr);
  printf("%d\n", n - maxr);
}
