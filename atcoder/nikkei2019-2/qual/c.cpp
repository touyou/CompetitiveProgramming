#include <bits/stdc++.h>
using namespace std;
int n;
int a[100000], b[100000];
int main() {
  scanf("%d", &n);
  for (auto i = 0; i < n; i++) scanf("%d", a + i);
  for (auto i = 0; i < n; i++) scanf("%d", b + i);
  sort(a, a + n);
  sort(b, b + n);
  bool flag = true;
  for (auto i = 0; i < n; i++) {
    if (a[i] > b[i]) flag = false;
  }
  puts(flag ? "Yes" : "No");
}
