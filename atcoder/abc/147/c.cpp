#include <bits/stdc++.h>
using namespace std;
int n;
int a;
int ma[16][16];
int main() {
  scanf("%d", &n);
  for (auto i = 0; i < n; i++)
    for (auto j = 0; j < n; j++) ma[i][j] = -1;
  for (auto i = 0; i < n; i++) {
    scanf("%d", &a);
    for (auto j = 0; j < a; j++) {
      int x, y;
      scanf("%d%d", &x, &y);
      ma[i][x - 1] = y;
    }
  }
}
