#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pii> data;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    data.push_back(pii(a, b));
  }
  sort(data.begin(), data.end());
  ll res = 0;
  for (int i = 0; i < data.size(); i++) {
    if (data[i].second <= m) {
      res += (ll)data[i].first * data[i].second;
      m -= data[i].second;
    } else {
      res += (ll)data[i].first * m;
      break;
    }
  }
  printf("%lld\n", res);
}
