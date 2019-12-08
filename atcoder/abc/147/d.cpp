#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
int main() {
  int n;
  scanf("%d", &n);
  vector<ll> as;
  for (auto i = 0; i < n; i++) {
    ll a;
    cin >> a;
    as.push_back(a);
  }
  ll res = 0;
  for (auto i = 0; i < n; i++) {
    for (auto j = i + 1; j < n; j++) {
      res = (res + (as[i] ^ as[j])) % MOD;
    }
  }
  cout << res << endl;
}
