#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
  int n;
  scanf("%d", &n);
  int a, b;
  vector<pii> edges;
  for (auto i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    edges.emplace_back(a, b);
  }
  int coin[n] = {1};
}
