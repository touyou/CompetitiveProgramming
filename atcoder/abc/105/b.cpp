#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  bool flag = false;
  for (int i = 0; i <= 25; i++) {
    if (n < i * 4) break;
    if ((n - i * 4) % 7 == 0) {
      flag = true;
      break;
    }
  }
  if (flag) puts("Yes");
  else puts("No");
}
