#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  int a[n];
  for (auto i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  ll ret = 0;
  int b[n];
  b[n - 1] = a[n - 1];
  for (auto i = n - 1; i >= 0; i--) {
    if (a[i] > i) {
      puts("-1");
      return 0;
    }
    if (i != n - 1) {
      b[i] = max(b[i + 1] - 1, a[i]);
    }
    if (i != n - 1 && a[i + 1] - 1 == a[i]) {
      continue;
    }
    if (b[i] > a[i]) {
      puts("-1");
      return 0;
    }
    ret += (ll)a[i];
  }
  printf("%lld\n", ret);
  return 0;
}
